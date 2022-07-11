#include "Profiler.h"

#include <iostream>
#include <mutex>  // mutex 를 사용하기 위해 필요
#include <thread>
#include <vector>

constexpr size_t cache_line_size = 64;
constexpr size_t num_iter = 1000000000;
constexpr size_t num_thread = 4;

void worker0(const int* data, const size_t work_load, size_t& result)
{
	for (size_t i = 0; i < work_load; i++)
	{
		result += data[i];
	}
}
void worker1(const int* data, const size_t work_load, size_t& result)
{
	size_t local_result = 0;
	for (size_t i = 0; i < work_load; i++)
	{
		local_result += data[i];
	}

	result += local_result;
}
void worker2(const int* data, const size_t work_load, size_t& result, std::mutex& m)
{
	size_t local_result = 0;
	for (size_t i = 0; i < work_load; i++)
	{
		local_result += data[i];
	}

	std::lock_guard<std::mutex> lock(m);
	result += local_result;
}

void test0(const std::vector<int>& values)
{
  size_t result = 0;
	worker0(values.data(), num_iter, result);

  std::cout << "최종 값 : " << result << std::endl;
}
void test0_using_single_thread(const std::vector<int>& values)
{
	size_t result = 0;		
	auto worker = std::thread(worker0, values.data(), num_iter, std::ref(result));
	worker.join();

	std::cout << "최종 값 : " << result << std::endl;
}
void test0_using_multi_thread(const std::vector<int>& values)
{
	constexpr auto work_load_per_thread = num_iter / num_thread;

	std::vector<size_t> results(num_thread);

	std::vector<std::thread> workers;
	for (size_t i = 0; i < num_thread; ++i)
	{
		const auto data_point = values.data() + i * work_load_per_thread;
		workers.push_back(std::thread(worker0, data_point, work_load_per_thread, std::ref(results[i])));
	}

	for (size_t i = 0; i < num_thread; i++)
	{
		workers[i].join();
	}

	size_t final_result = 0;
	for (const auto result : results)
	{
		final_result += result;
	}

	std::cout << "최종 값 : " << final_result << std::endl;
}

void test1(const std::vector<int>& values)
{
	size_t result = 0;
	worker1(values.data(), num_iter, result);

	std::cout << "최종 값 : " << result << std::endl;
}
void test1_using_single_thread(const std::vector<int>& values)
{
	size_t result = 0;
	auto worker = std::thread(worker1, values.data(), num_iter, std::ref(result));
	worker.join();

	std::cout << "최종 값 : " << result << std::endl;
}
void test1_using_multi_thread(const std::vector<int>& values)
{
	constexpr auto work_load_per_thread = num_iter / num_thread;

	std::vector<size_t> results(num_thread);

	std::vector<std::thread> workers;
	for (size_t i = 0; i < num_thread; ++i)
	{
		const auto data_point = values.data() + i * work_load_per_thread;
		workers.push_back(std::thread(worker1, data_point, work_load_per_thread, std::ref(results[i])));
	}

	for (size_t i = 0; i < num_thread; i++)
	{
		workers[i].join();
	}

	size_t final_result = 0;
	for (const auto result : results)
	{
		final_result += result;
	}

	std::cout << "최종 값 : " << final_result << std::endl;
}

void test2(const std::vector<int>& values)
{
	std::mutex m;

	size_t result = 0;
	worker2(values.data(), num_iter, result, m);

	std::cout << "최종 값 : " << result << std::endl;
}
void test2_using_single_thread(const std::vector<int>& values)
{
	std::mutex m;

	size_t result = 0;
	auto worker = std::thread(worker2, values.data(), num_iter, std::ref(result), std::ref(m));
	worker.join();

	std::cout << "최종 값 : " << result << std::endl;
}
void test2_using_multi_thread(const std::vector<int>& values)
{
	std::mutex m;

	constexpr auto work_load_per_thread = num_iter / num_thread;

	size_t result = 0;

	std::vector<std::thread> workers;
	for (size_t i = 0; i < num_thread; ++i)
	{
		const auto data_point = values.data() + i * work_load_per_thread;
		workers.push_back(std::thread(worker2, data_point, work_load_per_thread, std::ref(result), std::ref(m)));
	}

	for (size_t i = 0; i < num_thread; i++)
	{
		workers[i].join();
	}

	std::cout << "최종 값 : " << result << std::endl;
}



int main() 
{
	std::vector<int> v_g(num_iter);
	for (auto& val : v_g)
	{
		val = std::rand();
	}

	{
		std::cout << "test0 start \n";
		const auto begin_tp = Profiler::get_time_point();
		test0(v_g);
		const auto end_tp = Profiler::get_time_point();
		std::cout << "test0_time_duration : " << Profiler::calculate_duration(begin_tp, end_tp) << "\n\n";
	}
	//{
	//	std::cout << "test0_with_clock start \n";
	//	const auto begin_tp = Profiler::get_time_point();
	//	test0_with_clock();
	//	const auto end_tp = Profiler::get_time_point();
	//	std::cout << "test0_with_clock_time_duration : " << Profiler::calculate_duration(begin_tp, end_tp) << "\n\n";
	//}
	{
		std::cout << "test0_using_single_thread start \n";
		const auto begin_tp = Profiler::get_time_point();
		test0_using_single_thread(v_g);
		const auto end_tp = Profiler::get_time_point();
		std::cout << "test0_using_single_thread_time_duration : " << Profiler::calculate_duration(begin_tp, end_tp) << "\n\n";
	}
	{
		std::cout << "test0_using_multi_thread start \n";
		const auto begin_tp = Profiler::get_time_point();
		test0_using_multi_thread(v_g);
		const auto end_tp = Profiler::get_time_point();
		std::cout << "test0_using_multi_thread_time_duration : " << Profiler::calculate_duration(begin_tp, end_tp) << "\n\n";
	}
	{
		std::cout << "test1 start \n";
		const auto begin_tp = Profiler::get_time_point();
		test1(v_g);
		const auto end_tp = Profiler::get_time_point();
		std::cout << "test1_time_duration : " << Profiler::calculate_duration(begin_tp, end_tp) << "\n\n";
	}
	{
		std::cout << "test1_using_single_thread start \n";
		const auto begin_tp = Profiler::get_time_point();
		test1_using_single_thread(v_g);
		const auto end_tp = Profiler::get_time_point();
		std::cout << "test1_using_single_thread_time_duration : " << Profiler::calculate_duration(begin_tp, end_tp) << "\n\n";
	}
	{
		std::cout << "test1_using_multi_thread start \n";
		const auto begin_tp = Profiler::get_time_point();
		test1_using_multi_thread(v_g);
		const auto end_tp = Profiler::get_time_point();
		std::cout << "test1_using_multi_thread_time_duration : " << Profiler::calculate_duration(begin_tp, end_tp) << "\n\n";
	}
	{
		std::cout << "test2 start \n";
		const auto begin_tp = Profiler::get_time_point();
		test2(v_g);
		const auto end_tp = Profiler::get_time_point();
		std::cout << "test2_time_duration : " << Profiler::calculate_duration(begin_tp, end_tp) << "\n\n";
	}
	{
		std::cout << "test2_using_single_thread start \n";
		const auto begin_tp = Profiler::get_time_point();
		test2_using_single_thread(v_g);
		const auto end_tp = Profiler::get_time_point();
		std::cout << "test2_using_single_thread_time_duration : " << Profiler::calculate_duration(begin_tp, end_tp) << "\n\n";
	}
	{
		std::cout << "test2_using_multi_thread start \n";
		const auto begin_tp = Profiler::get_time_point();
		test2_using_multi_thread(v_g);
		const auto end_tp = Profiler::get_time_point();
		std::cout << "test2_using_multi_thread_time_duration : " << Profiler::calculate_duration(begin_tp, end_tp) << "\n\n";
	}

	//{
	//	std::cout << "test0_using_thread_with_clock start \n";
	//	const auto begin_tp = Profiler::get_time_point();
	//	test0_using_thread_with_clock();
	//	const auto end_tp = Profiler::get_time_point();
	//	std::cout << "test0_using_thread_with_clock_time_duration : " << Profiler::calculate_duration(begin_tp, end_tp) << "\n\n";
	//}

	//{
	//	const auto begin_tp = Profiler::get_time_point();
	//	test0_1();
	//	const auto end_tp = Profiler::get_time_point();
	//	std::cout << "test0_1_time_duration : " << Profiler::calculate_duration(begin_tp, end_tp) << "\n";
	//}

	//Profiler::set_time_point();
	//test0_1();
	//const auto test0_1_time_duration = Profiler::get_time_duration();
	//std::cout << "test0_1_time_duration : " << test0_1_time_duration << "\n";

 // Profiler::set_time_point();
 // test1();
 // const auto test1_time_duration = Profiler::get_time_duration();
 // std::cout << "test1_time_duration : " << test1_time_duration << "\n";

 // Profiler::set_time_point();
 // test2();
 // const auto test2_time_duration = Profiler::get_time_duration();
 // std::cout << "test2_time_duration : " << test2_time_duration << "\n";

	//Profiler::set_time_point();
	//test2_1();
	//const auto test2_1_time_duration = Profiler::get_time_duration();
	//std::cout << "test2_1_time_duration : " << test2_1_time_duration << "\n";

 // Profiler::set_time_point();
 // test3();
 // const auto test3_time_duration = Profiler::get_time_duration();
 // std::cout << "test3_time_duration : " << test3_time_duration << "\n";
}






//void worker0_with_clock(size_t& count)
//{
//	const auto begin_tp = Profiler::get_time_point();
//
//	for (size_t j = 0; j < num_iter; j++)
//	{
//		count += v_g[j];
//	}
//
//	const auto end_tp = Profiler::get_time_point();
//	std::cout << "worker0 working time : " << Profiler::calculate_duration(begin_tp, end_tp) << "\n";
//}

//void test0_with_clock(void)
//{
//	size_t counter = 0;
//	worker0_with_clock(counter);
//
//	std::cout << "Counter 최종 값 : " << counter << std::endl;
//}
//void test0_using_thread_with_clock(void)
//{
//	size_t count = 0;
//
//	auto worker = std::thread(worker0_with_clock, std::ref(count));
//	worker.join();
//
//	std::cout << "Counter 최종 값 : " << count << std::endl;
//}

//void test1(void)
//{
//  size_t total_count = 0;
//  std::mutex m;
//
//  std::vector<std::thread> workers;
//  for (size_t i = 0; i < num_thread; i++) 
//  {
//    workers.push_back(std::thread(worker1,  std::ref(total_count), std::ref(m)));
//  }
//
//  for (size_t i = 0; i < num_thread; i++) 
//  {
//    workers[i].join();
//  }
//
//  std::cout << "Counter 최종 값 : " << total_count << std::endl;
//}

//void test2(void)
//{
//  std::vector<size_t> counts(num_thread);
//
//  std::vector<std::thread> workers;
//  for (size_t i = 0; i < num_thread; ++i)
//  {
//    workers.push_back(std::thread(worker2, std::ref(counts[i])));
//  }
//
//  for (size_t i = 0; i < num_thread; i++)
//  {
//    workers[i].join();
//  }
//
//  size_t total_count = 0;
//  for (const auto count : counts)
//  {
//    total_count += count;
//  }
//
//  std::cout << "Counter 최종 값 : " << total_count << std::endl;
//}
//
//void test2_1(void)
//{
//	constexpr auto num_padding_element = cache_line_size / sizeof(size_t);
//	constexpr auto num_total_element = num_padding_element * (num_thread - 1 ) + 1;
//	std::vector<size_t> counts(num_total_element);
//	
//	std::vector<std::thread> workers;
//	for (size_t i = 0; i < num_thread; ++i)
//	{
//		workers.push_back(std::thread(worker2, std::ref(counts[i*num_padding_element])));
//	}
//
//	for (size_t i = 0; i < num_thread; i++)
//	{
//		workers[i].join();
//	}
//
//	size_t total_count = 0;
//	for (size_t i = 0; i < num_thread; ++i)
//	{
//		total_count += counts[i*num_padding_element];
//	}
//
//	std::cout << "Counter 최종 값 : " << total_count << std::endl;
//}
//
//void test3(void)
//{
//  std::vector<size_t> counts(num_thread);
//
//  std::vector<std::thread> workers;
//  for (size_t i = 0; i < num_thread; ++i)
//  {
//    workers.push_back(std::thread(worker3, std::ref(counts[i])));
//  }
//
//  for (size_t i = 0; i < num_thread; i++)
//  {
//    workers[i].join();
//  }
//
//  size_t total_count = 0;
//  for (const auto count : counts)
//  {
//    total_count += count;
//  }
//
//  std::cout << "Counter 최종 값 : " << total_count << std::endl;
//}