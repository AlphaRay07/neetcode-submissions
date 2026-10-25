class Solution {
public:
    unordered_map<int, vector<int>> courses;
    unordered_set<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<numCourses;i++){
            courses[i]={};
        }
        
        for(auto a: prerequisites){
            courses[a[0]].push_back(a[1]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(!dfs(i)) return false;
        }
        
        return true;
    }

    bool dfs(int course){
        if(courses[course].empty()) return true;
        if(visited.count(course)) return false;

        visited.insert(course);
        for(int b: courses[course]){
            if(!dfs(b)) return false;
        }

        visited.erase(course);
        courses[course].clear();
        return true;
    }
};
