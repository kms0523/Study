#include "Profiler.h"

#include <iostream>
#include <mutex>  // mutex 를 사용하기 위해 필요
#include <thread>
#include <vector>

constexpr size_t num_iter = 1000000000;
constexpr size_t num_thread = 2;

void worker1(size_t& result, std::mutex& m) 
{
  size_t local_sum = 0;
  for (size_t i = 0; i < num_iter; i++) 
  {    
    local_sum += i;
  }

  std::lock_guard<std::mutex> lock(m);
  result += local_sum;
}

void worker2(size_t& result) 
{
  for (size_t i = 0; i < num_iter; i++)
  {
    result += i;
  }
}

void worker3(size_t& result)
{
  size_t local_sum = 0;
  for (size_t i = 0; i < num_iter; i++)
  {
    local_sum += i;
  }

  result += local_sum;
}


void test0(void)
{
  size_t counter = 0;
  for (size_t i = 0; i < num_thread; i++)
  {
    for (size_t j = 0; j < num_iter; j++)
    {
      counter += j;
    }
  }

  std::cout << "Counter 최종 값 : " << counter << std::endl;
}

void test1(void)
{
  size_t total_count = 0;
  std::mutex m;

  std::vector<std::thread> workers;
  for (size_t i = 0; i < num_thread; i++) 
  {
    workers.push_back(std::thread(worker1, std::ref(total_count), std::ref(m)));
  }

  for (size_t i = 0; i < num_thread; i++) 
  {
    workers[i].join();
  }

  std::cout << "Counter 최종 값 : " << total_count << std::endl;
}

void test2(void)
{
  std::vector<size_t> counts(num_thread);

  std::vector<std::thread> workers;
  for (size_t i = 0; i < num_thread; ++i)
  {
    workers.push_back(std::thread(worker2, std::ref(counts[i])));
  }

  for (size_t i = 0; i < num_thread; i++)
  {
    workers[i].join();
  }

  size_t total_count = 0;
  for (const auto count : counts)
  {
    total_count += count;
  }

  std::cout << "Counter 최종 값 : " << total_count << std::endl;
}

void test3(void)
{
  std::vector<size_t> counts(num_thread);

  std::vector<std::thread> workers;
  for (size_t i = 0; i < num_thread; ++i)
  {
    workers.push_back(std::thread(worker3, std::ref(counts[i])));
  }

  for (size_t i = 0; i < num_thread; i++)
  {
    workers[i].join();
  }

  size_t total_count = 0;
  for (const auto count : counts)
  {
    total_count += count;
  }

  std::cout << "Counter 최종 값 : " << total_count << std::endl;
}

int main() 
{
  Profiler::set_time_point();
  test0();
  const auto test0_time_duration = Profiler::get_time_duration();
  std::cout << "test0_time_duration : " << test0_time_duration << "\n";

  Profiler::set_time_point();
  test1();
  const auto test1_time_duration = Profiler::get_time_duration();
  std::cout << "test1_time_duration : " << test1_time_duration << "\n";

  Profiler::set_time_point();
  test2();
  const auto test2_time_duration = Profiler::get_time_duration();
  std::cout << "test2_time_duration : " << test2_time_duration << "\n";

  Profiler::set_time_point();
  test3();
  const auto test3_time_duration = Profiler::get_time_duration();
  std::cout << "test3_time_duration : " << test3_time_duration << "\n";
}