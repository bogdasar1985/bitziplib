#include <catch2/catch_all.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cstddef>
#include <string>
#include "dynamic_array.hpp"
#include "huffman.hpp"
#include "utility.hpp"

/**
 *
 * Dynamic array tests
 *
 */
TEST_CASE( "Dynamic array init", "[dynamic_array]" ) 
{
	dynamic_array<int> arr;
	REQUIRE(arr.capacity() == 16);
	REQUIRE(arr.size() == 0);
}

TEST_CASE( "Dynamic array reserve" , "[dynamic_array]") 
{
	dynamic_array<int> arr;
	REQUIRE(arr.capacity() == 16);
	arr.reserve(8);
	REQUIRE(arr.capacity() == 16);
	arr.reserve(32);
	REQUIRE(arr.capacity() == 32);
}

TEST_CASE( "Dynamic array push_back", "[dynamic_array]")
{
	dynamic_array<int> arr;
	for(size_t i = 0; i < 16; i++)
	{
		arr.push_back(i);
	}
	REQUIRE(arr.size() == 16);
	REQUIRE(arr.capacity() == 16);
	arr.push_back(1);
	REQUIRE(arr.size() == 17);
	REQUIRE(arr.capacity() == 32);
}

/**
 *
 * Huffman piority queue size test
 *
 */
TEST_CASE( "Priority queue size test", "[huf_priority_queue]")
{
	hf_priority_queue pq;
	tree_node tmp_node;
	// a - 5; b - 1; c - 2; d - 4; e - 3
	std::string str = "aaaaaddddeeeccb";
	for(size_t i = 0; i < str.size(); i++)
	{
		pq.add({str[i]});
	}

	REQUIRE(pq.size() == 5);
	REQUIRE(((pq.top().count == 1) && (pq.top().sym == 'b')));
	tmp_node = pq.extract_min();
	REQUIRE(((tmp_node.count == 1) && (tmp_node.sym == 'b')));

	REQUIRE(pq.size() == 4);
	REQUIRE(((pq.top().count == 2) && (pq.top().sym == 'c')));
	tmp_node = pq.extract_min();
	REQUIRE(((tmp_node.count == 2) && (tmp_node.sym == 'c')));

	REQUIRE(pq.size() == 3);
	REQUIRE(((pq.top().count == 3) && (pq.top().sym == 'e')));
	tmp_node = pq.extract_min();
	REQUIRE(((tmp_node.count == 3) && (tmp_node.sym == 'e')));

	REQUIRE(pq.size() == 2);
	REQUIRE(((pq.top().count == 4) && (pq.top().sym == 'd')));
	tmp_node = pq.extract_min();
	REQUIRE(((tmp_node.count == 4) && (tmp_node.sym == 'd')));

	REQUIRE(pq.size() == 1);
	REQUIRE(((pq.top().count == 5) && (pq.top().sym == 'a')));
	tmp_node = pq.extract_min();
	REQUIRE(((tmp_node.count == 5) && (tmp_node.sym == 'a')));
}

/**
 *
 * Huffman priority queue add test
 *
 */
TEST_CASE( "Priority queue add test", "[huf_priority_queue]" )
{
	hf_priority_queue pq;
	// a - 5; d - 4; e - 3; c - 2; b - 1
	std::string str = "aaaaaddddeeeccb";
	size_t i = 0;
	for(; i < 5; i++)
	{
		pq.add({str[i]});
	}
	REQUIRE(pq.size() == 1);
	REQUIRE(pq.top().sym == 'a');

	for(; i < 9; i++)
	{
		pq.add({str[i]});
	}
	REQUIRE(pq.size() == 2);
	REQUIRE(pq.top().sym == 'd');
}


/**
 *
 * Huffman priority queue extract min test
 *
 */
TEST_CASE( "Prioirity queue extract min test", "[huf_priority_queue]")
{
	hf_priority_queue pq;
	tree_node tmp_node;
	// a - 5; b - 1; c - 2; d - 4; e - 3
	std::string str = "aaaaaddddeeeccb";
	for(size_t i = 0; i < str.size(); i++)
	{
		pq.add({str[i]});
	}
	tmp_node = pq.extract_min();
	REQUIRE(((tmp_node.sym == 'b') && (tmp_node.count == 1)));
	tmp_node = pq.extract_min();
	REQUIRE(((tmp_node.sym == 'c') && (tmp_node.count == 2)));
}

/**
 *
 * D
 *
 */
