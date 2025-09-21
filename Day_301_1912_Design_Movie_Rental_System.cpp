#include <bits/stdc++.h>
using namespace std;
// Node structure to represent a movie rental entry
struct Node {
    int shop, movie, price;
    // Custom comparator for sorting: first by price, then by shop, then by movie
    bool operator<(const Node& other) const {
        if (price != other.price) return price < other.price;
        if (shop != other.shop) return shop < other.shop;
        return movie < other.movie;
    }
};

class MovieRentingSystem {
    // Map to store shop-movie pair to Node mapping using encoded key
    unordered_map<long long, Node> byPair;
    // Map to store available movies grouped by movie ID, sorted by Node comparator
    unordered_map<int, set<Node>> availableByMovie;
    // Set to store currently rented movies, sorted by Node comparator
    set<Node> rentedSet;

    // Encode shop and movie IDs into a single long long key
    long long key(int shop, int movie) {
        return ((long long)shop << 32) ^ movie;
    }

public:
    // Constructor: Initialize the system with movie entries
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            Node node{shop, movie, price};
            // Store the node for quick lookup by shop-movie pair
            byPair[key(shop, movie)] = node;
            // Add to available movies set for this movie ID
            availableByMovie[movie].insert(node);
        }
    }

    // Search for cheapest 5 available shops for a given movie
    vector<int> search(int movie) {
        vector<int> res;
        if (availableByMovie.count(movie) == 0) return res;
        auto& s = availableByMovie[movie];
        int count = 0;
        // Get first 5 shops (sorted by price, then shop, then movie)
        for (auto it = s.begin(); it != s.end() && count < 5; ++it, ++count) {
            res.push_back(it->shop);
        }
        return res;
    }

    // Rent a movie from a specific shop
    void rent(int shop, int movie) {
        long long k = key(shop, movie);
        Node node = byPair[k];
        // Remove from available movies
        availableByMovie[movie].erase(node);
        // Add to rented movies set
        rentedSet.insert(node);
    }

    // Return a rented movie back to available pool
    void drop(int shop, int movie) {
        long long k = key(shop, movie);
        Node node = byPair[k];
        // Remove from rented movies
        rentedSet.erase(node);
        // Add back to available movies
        availableByMovie[movie].insert(node);
    }

    // Report the cheapest 5 rented movies
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int count = 0;
        // Get first 5 rented movies (sorted by price, then shop, then movie)
        for (auto it = rentedSet.begin(); it != rentedSet.end() && count < 5; ++it, ++count) {
            res.push_back({it->shop, it->movie});
        }
        return res;
    }
};