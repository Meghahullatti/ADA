#include <stdio.h>
#include <stdlib.h>

#define MAX_COURSES 1000


int dfs(int course, int** adj, int* visited, int* recStack, int numCourses) {
    if (recStack[course]) {
        return 1;  
    }
    if (visited[course]) {
        return 0;  
    }

    // Mark the current course as visited and add to the recursion stack
    visited[course] = 1;
    recStack[course] = 1;

    // Visit all the prerequisites (adjacent courses)
    for (int i = 0; adj[course][i] != -1; i++) {
        if (adj[course][i] != -1 && dfs(adj[course][i], adj, visited, recStack, numCourses)) {
            return 1;  // Cycle detected
        }
    }

    // Remove the course from recursion stack after processing
    recStack[course] = 0;
    return 0;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    
    int** adj = (int**)malloc(numCourses * sizeof(int*));
    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(numCourses * sizeof(int));
        for (int j = 0; j < numCourses; j++) {
            adj[i][j] = -1;  
        }
    }

    // Build the adjacency list
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];

        // Append the prerequisite to the list for the current course
        int j = 0;
        while (adj[course][j] != -1) {  // Find the next available slot
            j++;
        }
        adj[course][j] = prereq;  // Store the prerequisite for the course
    }

    // Arrays to track visited nodes and recursion stack
    int visited[numCourses];
    int recStack[numCourses];

    for (int i = 0; i < numCourses; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    // Check for cycles in all the courses
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack, numCourses)) {
                return false;  // Cycle detected
            }
        }
    }

    return true;  // No cycles, so it's possible to finish all courses
}

// Helper function for testing
void printResult(bool result) {
    if (result) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}


