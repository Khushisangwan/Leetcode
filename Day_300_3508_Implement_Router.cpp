#include<bits/stdc++.h>
using namespace std;
class Router {
private:
    int size; // Memory limit for the router
    unordered_map<long long, vector<int>> packets; // Store packets with encoded key
    unordered_map<int, vector<int>> counts; // Store timestamps for each destination
    queue<long long> q; // FIFO queue for packet forwarding order

    // Encode source, destination, and timestamp into a single long long key
    long long encode(int source, int destination, int timestamp) {
        return ((long long)source << 40) | ((long long)destination << 20) | timestamp;
    }

    // Find the first position where element >= target
    int lowerBound(vector<int>& list, int target) {
        return (int)(lower_bound(list.begin(), list.end(), target) - list.begin());
    }

    // Find the first position where element > target
    int upperBound(vector<int>& list, int target) {
        return (int)(upper_bound(list.begin(), list.end(), target) - list.begin());
    }

public:
    // Constructor: Initialize router with memory limit
    Router(int memoryLimit) {
        size = memoryLimit;
    }

    // Add a new packet to the router
    bool addPacket(int source, int destination, int timestamp) {
        long long key = encode(source, destination, timestamp);

        // Check if packet already exists
        if (packets.find(key) != packets.end())
            return false;

        // If memory is full, forward the oldest packet
        if ((int)packets.size() >= size)
            forwardPacket();

        // Store the packet and add to queue
        packets[key] = {source, destination, timestamp};
        q.push(key);
        counts[destination].push_back(timestamp);

        return true;
    }

    // Forward (remove) the oldest packet from the router
    vector<int> forwardPacket() {
        if (packets.empty()) return {};

        // Get the oldest packet from queue
        long long key = q.front();
        q.pop();

        // Retrieve packet data and remove from storage
        vector<int> packet = packets[key];
        packets.erase(key);

        // Remove the corresponding timestamp from counts
        int dest = packet[1];
        counts[dest].erase(counts[dest].begin());  // remove earliest timestamp

        return packet;
    }

    // Count packets for a destination within a time range [startTime, endTime]
    int getCount(int destination, int startTime, int endTime) {
        auto it = counts.find(destination);
        if (it == counts.end() || it->second.empty())
            return 0;

        vector<int>& list = it->second;

        // Use binary search to find the range efficiently
        int left = lowerBound(list, startTime);
        int right = upperBound(list, endTime);

        return right - left;
    }
};