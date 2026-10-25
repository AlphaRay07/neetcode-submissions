class Solution {
public:
    unordered_map<int, vector<int>> courses;
    unordered_set<int> cycle;
    unordered_set<int> visited;
    vector<int> result;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<numCourses;i++){
            courses[i]={};
        }
        
        for(auto a: prerequisites){
            courses[a[0]].push_back(a[1]);
        }

        for(int i=0;i<numCourses;i++){
            if(!dfs(i)){
                return {};
            }
        }
        
        return result;
    }

    bool dfs(int course){
        if(visited.count(course)) return true;
        if(courses[course].empty()){visited.insert(course);result.push_back(course); return true;}
        if(cycle.count(course)) return false;

        cycle.insert(course);

        for(int b: courses.at(course)){
            if(!dfs(b)) return false;
        }

        cycle.erase(course);
        visited.insert(course);
        courses[course].clear();
        result.push_back(course);
        return true;
    }
};
