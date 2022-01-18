#include <iostream>
#include <vector>

using namespace std;






int main() {
    int v1, v2;
    scanf("%d %d", &v1, &v2);

    int nodes, edges;
    scanf("%d %d", &nodes, &edges);

    int parent, child;
    //vector<vector<int>> child_list (nodes + 1, vector<int>());
    vector<vector<int>> parent_list (nodes + 1, vector<int>());
    
    for(int i = 0; i < edges; i++){
        scanf("%d %d", &parent, &child);
        
        //child_list[parent].push_back(child);
        parent_list[child].push_back(parent);
    }
    
    




/*
// Child List ----------------------------
    cout << "Child List" << endl;
    int len1;
    for(int i = 1; i <= nodes; i++){
        len1 = child_list[i].size();
        cout << i << " --->";
        for(int j = 0; j < len1; j++){
            cout << " " << child_list[i][j];
        }
        cout << endl;
    }
    cout << endl;
// ---------------------------------------
*/
// Parent List ----------------------------
    cout << "Parent List" << endl;
    int len2;
    for(int i = 1; i <= nodes; i++){
        len2 = parent_list[i].size();
        cout << i << " --->";
        for(int j = 0; j < len2; j++){
            cout << " " << parent_list[i][j];
        }
        cout << endl;
    }
    cout << endl;
// ---------------------------------------

    return 0;
}