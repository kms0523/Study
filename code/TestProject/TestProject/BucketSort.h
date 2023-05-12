//#pragma once
//#include "MecCoordinate.h"
//#include <array>
//
//// miscellaneous definition
//namespace Mec
//{
//
//struct SearchResult
//{
//  idx_type  index;
//  real_type distance;
//};
//
//} // namespace Mec
//
//// class declaration
//namespace Mec
//{
//
//class BucketSortSimple
//{
//public:
//  void initialize(const std::vector<Coordinate>& coordiantes, const real_type bucket_size);
//
//public:
//  void search(std::vector<SearchResult>& results, const Coordinate& center, const double radius) const;
//
//private:
//  void     find_bucket_indexes(idx_type* bucket_indexes, const Coordinate& coordinate) const;
//  idx_type convert_to_bucket_id(const std::array<idx_type, 3>& bucket_indexes) const;
//  bool     is_valid_bucket_indexes(const std::array<idx_type, 3>& bucket_indexes) const;
//  idx_type num_total_buckets(void) const;
//  void     find_search_range(bool& no_need_to_search, blitz::Range* search_ranges, const Coordinate& center, const double radius) const;
//
//private:
//  static constexpr idx_type     _dim                  = 3;
//  static constexpr idx_type     _invalid_bucket_index = -20220425;
//  real_type                     _bucket_size          = 0.0;
//  const Coordinate*             _coordinates          = nullptr;
//  Coordinate                    _min_coordinate;
//  Coordinate                    _max_coordinate;
//  std::array<idx_type, 3>       _num_buckets_at_axis;
//  std::vector<std::vector<int>> _bucket_id_to_coordinate_indexes;
//};
//
//} // namespace Mec