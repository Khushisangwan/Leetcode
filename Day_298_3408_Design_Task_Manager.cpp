#include<bits/stdc++.h>
using namespace std;
/**
 * @class TaskManager
 * @brief A task management system that maintains tasks with priorities and executes them in order.
 * 
 * This class implements a priority-based task queue where tasks are ordered by:
 * 1. Priority (higher priority first)
 * 2. Task ID (larger ID first for same priority)
 * 
 * The TaskManager uses a map-based approach for efficient insertion, deletion, and
 * priority-based ordering of tasks.
 */

/**
 * @struct Task
 * @brief Represents a task with an ID and priority level.
 * 
 * Contains comparison operator for priority queue ordering:
 * - Higher priority tasks come first
 * - For equal priorities, tasks with larger IDs come first
 */

/**
 * @brief Constructs a TaskManager with initial tasks.
 * @param tasks Vector of task vectors, each containing [userId, taskId, priority]
 * 
 * Initializes the task manager with the provided tasks, setting up both
 * the priority queue and the task-to-priority mapping.
 */

/**
 * @brief Adds a new task to the task manager.
 * @param userId The ID of the user who owns the task
 * @param taskId Unique identifier for the task
 * @param priority Priority level of the task (higher values = higher priority)
 * 
 * If a task with the same taskId already exists, it will be overwritten.
 */

/**
 * @brief Modifies the priority of an existing task.
 * @param taskId The ID of the task to modify
 * @param newPriority The new priority level for the task
 * 
 * Removes the task with old priority and re-inserts it with new priority.
 * Assumes the task exists in the system.
 */

/**
 * @brief Removes a task from the task manager.
 * @param taskId The ID of the task to remove
 * 
 * If the task doesn't exist, the operation is ignored.
 * Removes the task from both the priority queue and priority mapping.
 */

/**
 * @brief Executes and removes the highest priority task.
 * @return The userId of the executed task, or -1 if no tasks exist
 * 
 * Returns the userId associated with the task that has:
 * 1. Highest priority, or
 * 2. Largest taskId among tasks with the same highest priority
 * 
 * The executed task is removed from the system.
 */
class TaskManager {
    struct Task {
        int taskId;
        int priority;
        bool operator<(const Task &other) const {
            if (priority != other.priority)
                return priority > other.priority; // higher first
            return taskId > other.taskId;        // larger id first
        }
    };

    map<Task, int> taskQueue;
    unordered_map<int, int> taskPriorityMap;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            taskQueue[{taskId, priority}] = userId;
            taskPriorityMap[taskId] = priority;
        }
    }

    void add(int userId, int taskId, int priority) {
        taskQueue[{taskId, priority}] = userId;
        taskPriorityMap[taskId] = priority;
    }

    void edit(int taskId, int newPriority) {
        int oldPriority = taskPriorityMap[taskId];
        int userId = taskQueue[{taskId, oldPriority}];
        taskQueue.erase({taskId, oldPriority});
        taskQueue[{taskId, newPriority}] = userId;
        taskPriorityMap[taskId] = newPriority;
    }

    void rmv(int taskId) {
        if (!taskPriorityMap.count(taskId)) return;
        int priority = taskPriorityMap[taskId];
        taskQueue.erase({taskId, priority});
        taskPriorityMap.erase(taskId);
    }

    int execTop() {
        if (taskQueue.empty()) return -1;
        auto it = taskQueue.begin();
        int userId = it->second;
        taskPriorityMap.erase(it->first.taskId);
        taskQueue.erase(it);
        return userId;
    }
};