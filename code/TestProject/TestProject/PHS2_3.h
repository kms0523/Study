#pragma once
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int alphabet_to_index(const char c)
{
  return c - 'a';
}

struct Node
{
public:
  Node(const int index)
      : _index(index){};

public:
  void add_outgoing_index(const int index)
  {
    this->_outgoing_indexes_.push_back(index);
  }
  void add_incoming_index(const int index)
  {
    this->_incoming_indexes_.push_back(index);
  }

public:
  int out_degree(void) const
  {
    return static_cast<int>(this->_outgoing_indexes_.size());
  }
  int in_degree(void) const
  {
    return static_cast<int>(this->_incoming_indexes_.size());
  }

public:
  int              _index;
  std::vector<int> _incoming_indexes_;
  std::vector<int> _outgoing_indexes_;
};

class Graph
{
public:
  void add_node(const int index)
  {
    this->_index_to_node.emplace(index, Node(index));
  }

  Node& node(const int index)
  {
    return this->_index_to_node.at(index);
  }

public:
  bool has_node(const int index) const
  {
    return this->_index_to_node.find(index) != this->_index_to_node.end();
  }

  bool is_connected(const int start_node_index) const
  {
    std::unordered_set<int> visited_indexes;
    std::vector<int>        indexes_to_visit;
    indexes_to_visit.reserve(this->_index_to_node.size());

    if (start_node_index == Graph::has_euler_circit)
    {
      indexes_to_visit.push_back(this->_index_to_node.begin()->first);
    }
    else
    {
      indexes_to_visit.push_back(start_node_index);
    }

    while (true)
    {
      const auto index_to_visit = indexes_to_visit.back();
      indexes_to_visit.pop_back();

      visited_indexes.insert(index_to_visit);

      const auto& visiting_node = this->_index_to_node.at(index_to_visit);
      for (const auto index : visiting_node._outgoing_indexes_)
      {
        if (index == visiting_node._index) continue;

        if (visited_indexes.find(index) == visited_indexes.end())
        {
          indexes_to_visit.push_back(index);
        }
      }

      if (indexes_to_visit.empty())
      {
        break;
      }
    }

    return visited_indexes.size() == this->_index_to_node.size();
  }

  static constexpr int not_has_euler_trail = -100;
  static constexpr int has_euler_circit    = -523;

  std::pair<int, int> find_euler_trail_start_end_index(void) const
  {
    int one_index          = -1;
    int negative_one_index = -1;

    for (const auto& [index, node] : this->_index_to_node)
    {
      const auto out_degree = node.out_degree();
      const auto in_degree  = node.in_degree();
      const auto diff       = out_degree - in_degree;

      if (diff == 0)
      {
        continue;
      }
      else if (diff == 1)
      {
        if (one_index != -1) return { not_has_euler_trail, not_has_euler_trail };

        one_index = index;
      }
      else if (diff == -1)
      {
        if (negative_one_index != -1) return { not_has_euler_trail, not_has_euler_trail };

        negative_one_index = index;
      }
      else
      {
        return { not_has_euler_trail, not_has_euler_trail };
      }
    }

    if (one_index == -1)
    {
      return { has_euler_circit, has_euler_circit };
    }

    return { one_index, negative_one_index };
  }

private:
  std::unordered_map<int, Node> _index_to_node;
};

std::string solution1(int N, std::vector<std::string> W)
{
  Graph graph;

  for (const auto& word : W)
  {
    const auto front_index = alphabet_to_index(word.front());
    const auto back_index  = alphabet_to_index(word.back());

    if (!graph.has_node(front_index))
    {
      graph.add_node(front_index);
    }

    if (!graph.has_node(back_index))
    {
      graph.add_node(back_index);
    }

    graph.node(front_index).add_outgoing_index(back_index);
    graph.node(back_index).add_incoming_index(front_index);
  }

  const auto [start_index, end_index] = graph.find_euler_trail_start_end_index();

  if (start_index == Graph::not_has_euler_trail)
  {
    return "No";
  }

  if (graph.is_connected(start_index))
  {
    return "Yes";
  }
  else
  {
    return "No";
  }
}

std::vector<std::string> solution2(int N, std::vector<std::string> W)
{
  Graph graph;

  for (const auto& word : W)
  {
    const auto front_index = alphabet_to_index(word.front());
    const auto back_index  = alphabet_to_index(word.back());

    if (!graph.has_node(front_index))
    {
      graph.add_node(front_index);
    }

    if (!graph.has_node(back_index))
    {
      graph.add_node(back_index);
    }

    graph.node(front_index).add_outgoing_index(back_index);
    graph.node(back_index).add_incoming_index(front_index);
  }

  const auto [start_index, end_index] = graph.find_euler_trail_start_end_index();

  if (start_index == Graph::not_has_euler_trail)
  {
    return { "impossible" };
  }

  if (start_index == Graph::has_euler_circit)
  {
    std::sort(W.begin(), W.end());
    return W;
  }

  std::vector<std::string> candidate;
}