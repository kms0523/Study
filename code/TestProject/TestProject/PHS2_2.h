#pragma once
#include <algorithm>
#include <vector>

int solution1(std::vector<int> F)
{
  std::vector<int> ref = { 1, 2, 3, 4, 5, 6, 7, 8 };

  if (std::is_permutation(ref.begin(), ref.end(), F.begin()))
    return 1;
  else
    return 0;
}

int solution2(int N, std::vector<int> F, std::vector<int> B)
{
  const auto iter = std::search(F.begin(), F.end(), B.begin(), B.end());

  if (iter == F.end())
  {
    return -1;
  }
  else
  {
    return (iter - F.begin()) + 1;
  }
}

int cal_distance(const std::vector<int>& info, const std::vector<int>& code)
{
  const auto iter = std::search(info.begin(), info.end(), code.begin(), code.end());

  if (iter == info.end())
  {
    return -1;
  }
  else
  {
    return (iter - info.begin()) + 1;
  }
}

long long cal_gcd(long long a, long long b)
{
  long long mod = a % b;

  while (mod > 0)
  {
    a   = b;
    b   = mod;
    mod = a % b;
  }

  return b;
}

int solution3(int N, std::vector<int> F, std::vector<int> S, std::vector<int> B, int T)
{
  const auto first_distance  = cal_distance(F, B);
  const auto second_distance = cal_distance(S, B);

  const auto distance_diff = second_distance - first_distance;

  if (distance_diff == 0) return 0;

  int d = (distance_diff < 0) ? 1 : -1;

  auto numerator   = 60 * std::abs(distance_diff);
  auto denominator = T;

  const auto gcd = cal_gcd(numerator, denominator);

  if (gcd == 1) return { d * (numerator + denominator) };

  numerator /= gcd;
  denominator /= gcd;

  return { d * (numerator + denominator) };
}

int solution4(int N, std::vector<int> F, std::vector<int> S, std::vector<int> B, int T, int P, int Q)
{
  const auto first_distance  = cal_distance(F, B);
  const auto second_distance = cal_distance(S, B);

  const auto signal_diff = second_distance - first_distance;

  if (signal_diff == 0) return 0;

  int d = (signal_diff < 0) ? 1 : -1;

  auto numerator   = 60 * std::abs(signal_diff) * P;
  auto denominator = T * Q;

  const auto gcd = cal_gcd(numerator, denominator);

  if (gcd == 1) return { d * (numerator + denominator) };

  numerator /= gcd;
  denominator /= gcd;

  return { d * (numerator + denominator) };
}

long long cal_irreducible_fraction_sum(long long denominator, long long numerator)
{
  const auto gcd = cal_gcd(numerator, denominator);
  if (gcd == 1) return denominator + numerator;

  denominator /= gcd;
  numerator /= gcd;

  return denominator + numerator;
}

int solution5(int N, std::vector<int> F, std::vector<int> S, std::vector<int> B, int T, int P, int Q, int W, int O)
{
  constexpr auto val = 1000000009;
	
  const long long signal1    = cal_distance(F, B);
  const long long signal2    = cal_distance(S, B);
  const long long del_signal = signal2 - signal1;

  //distance = D1/N1
  const long long D1 = signal2 * P;
  const long long N1 = Q;

  //ally velocity = D2/N2
  const long long D2 = W;
  const long long N2 = O;

  //enemy velocity = D3/N3
  const long long D3 = del_signal * P * 60;
  const long long N3 = Q * T;

  //relative velocity = D2/N2 - D3/N3 = D4/N4
  const long long D4 = D2 * N3 - D3 * N2;
  const long long N4 = N2 * N3;

	if (D4 <= 0)
	{
		return -1;
	}

  //time = D5/N5 = D1/N1 / D4/N4
  const long long D5 = D1 * N4;
  const long long N5 = N1 * D4;

  return cal_irreducible_fraction_sum(D5, N5) % val;
}