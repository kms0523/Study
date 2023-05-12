//#include "MecBucketSortSimple.h"
//
//namespace Mec
//{
//real_type cal_distance(const Coordinate& c1, const Coordinate& c2)
//{
//  real_type distance = 0.0;
//  for (idx_type i = 0; i < 3; ++i)
//  {
//    const auto di = c1[i] - c2[i];
//    distance += di * di;
//  }
//
//  return std::sqrt(distance);
//}
//
//} // namespace Mec
//
//namespace Mec
//{
//
//void BucketSortSimple::initialize(const std::vector<Coordinate>& coordiantes, const real_type bucket_size)
//{
//  this->_bucket_size = bucket_size;
//  this->_coordinates = coordiantes.data();
//
//  //find min max
//  const auto num_coordinates = coordiantes.size();
//
//  this->_max_coordinate = coordiantes.front();
//  this->_min_coordinate = this->_max_coordinate;
//
//  for (auto i = 1; i < num_coordinates; ++i)
//  {
//    const auto& coordinate = coordiantes[i];
//
//    for (auto j = 0; j < _dim; ++j)
//    {
//      const auto val     = coordinate[j];
//      auto&      max_val = this->_max_coordinate[j];
//      auto&      min_val = this->_min_coordinate[j];
//
//      if (max_val < val) max_val = val;
//
//      if (val < min_val) min_val = val;
//    }
//  }
//
//  //set buckets
//  constexpr real_type idx_max = std::numeric_limits<idx_type>::max();
//
//  const auto c1 = 1 / this->_bucket_size;
//
//  Vector3D num_buckets_at_axis(3);
//
//  while (true)
//  {
//    for (auto i = 0; i < _dim; ++i)
//    {
//      num_buckets_at_axis[i] = std::floor((this->_max_coordinate(i) - this->_min_coordinate(i)) * c1) + 1;
//    }
//
//    const auto nbucket_real = num_buckets_at_axis(0) * num_buckets_at_axis(1) * num_buckets_at_axis(2);
//
//    if (nbucket_real < idx_max)
//    {
//      for (auto i = 0; i < _dim; ++i)
//      {
//        this->_num_buckets_at_axis[i] = static_cast<idx_type>(num_buckets_at_axis[i]);
//      }
//      break;
//    }
//    else
//    {
//      this->_bucket_size *= 2.0;
//    }
//  }
//
//  this->_bucket_id_to_coordinate_indexes.resize(this->num_total_buckets());
//
//  //sorting coordinates
//  std::array<idx_type, 3> bucket_indexes = { 0 };
//  for (auto i = 0; i < num_coordinates; ++i)
//  {
//    this->find_bucket_indexes(bucket_indexes.data(), coordiantes[i]);
//    const auto bucket_id = this->convert_to_bucket_id(bucket_indexes);
//
//    this->_bucket_id_to_coordinate_indexes[bucket_id].push_back(i);
//  }
//}
//
//void BucketSortSimple::search(std::vector<SearchResult>& results, const Coordinate& center, const double radius) const
//{
//  results.clear();
//
//  bool                           no_need_to_search = false;
//  std::array<blitz::Range, _dim> search_ranges;
//  this->find_search_range(no_need_to_search, search_ranges.data(), center, radius);
//
//  if (no_need_to_search) return;
//
//  const auto& x_range = search_ranges[0];
//  const auto& y_range = search_ranges[1];
//  const auto& z_range = search_ranges[2];
//
//  //search
//  const auto c1 = this->_num_buckets_at_axis[0];
//  const auto c2 = this->_num_buckets_at_axis[0] * this->_num_buckets_at_axis[1];
//
//  std::array<idx_type, _dim> search_bucket_indexes;
//  auto                       bucket_id = 0;
//  for (auto z_index = z_range.first(); z_index <= z_range.last(); ++z_index)
//  {
//    const auto c3 = z_index * c2;
//    for (auto y_index = y_range.first(); y_index <= y_range.last(); ++y_index)
//    {
//      const auto c4 = c3 + y_index * c1;
//      for (auto x_index = x_range.first(); x_index <= x_range.last(); ++x_index)
//      {
//        bucket_id                       = c4 + x_index;
//        const auto& coordinated_indexes = this->_bucket_id_to_coordinate_indexes[bucket_id];
//
//        for (const auto index : coordinated_indexes)
//        {
//          const auto& coordinate = this->_coordinates[index];
//          const auto  distance   = cal_distance(center, coordinate);
//
//          if (radius < distance) continue;
//
//          results.push_back({ index, distance });
//        }
//      }
//    }
//  }
//}
//
//void BucketSortSimple::find_bucket_indexes(idx_type* bucket_indexes, const Coordinate& coordinate) const
//{
//  const auto c1 = 1 / this->_bucket_size;
//
//  for (auto i = 0; i < _dim; ++i)
//  {
//    const auto coordinate_diff = coordinate(i) - this->_min_coordinate(i);
//    const auto index           = static_cast<idx_type>(coordinate_diff * c1);
//
//    bucket_indexes[i] = index;
//  }
//}
//
//idx_type BucketSortSimple::convert_to_bucket_id(const std::array<idx_type, 3>& bucket_indexes) const
//{
//  const auto x_index = bucket_indexes[0];
//  const auto y_index = bucket_indexes[1];
//  const auto z_index = bucket_indexes[2];
//  const auto num_x   = this->_num_buckets_at_axis[0];
//  const auto num_y   = this->_num_buckets_at_axis[1];
//
//  return x_index + y_index * num_x + z_index * num_x * num_y;
//}
//
//bool BucketSortSimple::is_valid_bucket_indexes(const std::array<idx_type, 3>& bucket_indexes) const
//{
//  return bucket_indexes.front() != this->_invalid_bucket_index;
//}
//
//idx_type BucketSortSimple::num_total_buckets(void) const
//{
//  auto num_total_buckets = 1;
//
//  for (const auto num : this->_num_buckets_at_axis)
//  {
//    num_total_buckets *= num;
//  }
//
//  return num_total_buckets;
//}
//
//void BucketSortSimple::find_search_range(bool& no_need_to_search, blitz::Range* search_ranges, const Coordinate& center, const double radius) const
//{
//  assert(radius > 0);
//
//  auto search_level = static_cast<idx_type>(std::ceil(radius / this->_bucket_size));
//
//  std::array<idx_type, _dim> center_bucket_indexes;
//  this->find_bucket_indexes(center_bucket_indexes.data(), center);
//
//  for (auto i = 0; i < _dim; ++i)
//  {
//    const auto start_index = center_bucket_indexes[i] - search_level;
//    const auto end_index   = center_bucket_indexes[i] + search_level;
//
//    const auto min_index = 0;
//    const auto max_index = this->_num_buckets_at_axis[i] - 1;
//
//    auto search_start_index = this->_invalid_bucket_index;
//    auto search_end_index   = this->_invalid_bucket_index;
//
//    //find start index
//    if (start_index <= min_index)
//    {
//      search_start_index = min_index;
//    }
//    else if (start_index <= max_index)
//    {
//      search_start_index = start_index;
//    }
//    else
//    {
//      no_need_to_search = true;
//      break;
//    }
//
//    //find end index
//    if (end_index <= min_index)
//    {
//      no_need_to_search = true;
//      break;
//    }
//    else if (end_index <= max_index)
//    {
//      search_end_index = end_index;
//    }
//    else
//    {
//      search_end_index = max_index;
//    }
//
//    // set range
//    if (search_start_index == search_end_index)
//    {
//      search_ranges[i] = blitz::Range(search_start_index);
//    }
//    else
//    {
//      search_ranges[i] = blitz::Range(search_start_index, search_end_index);
//    }
//  }
//}
//
//} // namespace Mec