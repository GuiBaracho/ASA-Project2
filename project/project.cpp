#include <iostream>
#include <vector>
#include <list>

using namespace std;

#define WHITE (0)
#define GRAY (1)
#define BLACK (2)
#define V1 (3)
#define V2 (4)

typedef struct {
    int c = WHITE;
    int anc = -1;
    int p_i = 0;
    int p[2];
} node;

void print_parent(vector<node> &parent_list, int nodes){
    // Parent List ----------------------------
    cout << "Parent List" << endl;
    int len2;
    for(int i = 1; i <= nodes; i++){
        len2 = parent_list[i].p_i;
        cout << i << " Color = " << parent_list[i].anc << " --->";
        for(int j = 0; j < len2; j++){
            cout << " " << parent_list[i].p[j];
        }
        cout << endl;
    }
    cout << endl;
// ---------------------------------------
}

void set_white(vector<node> &parent_list){
    int len = parent_list.size();
    for(int i = 1; i < len; i++){
        parent_list[i].c = WHITE;
    }
}

void check_visit(vector<node> &parent_list, int v){
    int p_i = parent_list[v].p_i;
    parent_list[v].c = GRAY;
    for(int i = 0; i < p_i; i++){
        int p = parent_list[v].p[i];
        if(parent_list[p].c == GRAY){
            cout << "0" << endl;
            exit(0);
        } else if (parent_list[p].c == WHITE){
            check_visit(parent_list, p);
        }
    }
    parent_list[v].c = BLACK;
}

void check(vector<node> &parent_list){
    int len = parent_list.size();
    for(int i = 1; i < len; i++){
        if(parent_list[i].c == WHITE){
            check_visit(parent_list, i);
        }
    }
}


void dfs_v1(vector<node> &parent_list, int v){
    int p_i = parent_list[v].p_i;
    parent_list[v].c = BLACK;
    parent_list[v].anc = V1;
    for(int i = 0; i < p_i; i++){
        int p = parent_list[v].p[i];
        if (parent_list[p].c == WHITE){
            dfs_v1(parent_list, p);
        }
    }
}


void dfs_v2(vector<node> &parent_list, int v){
    int p_i = parent_list[v].p_i;
    parent_list[v].c = BLACK;
    if(parent_list[v].anc == V1){
        parent_list[v].anc = V2;
    }
    for(int i = 0; i < p_i; i++){
        int p = parent_list[v].p[i];
        if (parent_list[p].c == WHITE){
            dfs_v2(parent_list, p);
        }
    }
}

void closest_common_ancester(vector<node> &parent_list, vector<vector<int>> child_list, int v1, int v2){
    int control = 0;
    set_white(parent_list);
    dfs_v1(parent_list, v1);

    //print_parent(parent_list, 8);

    set_white(parent_list);
    dfs_v2(parent_list, v2);
    int len = parent_list.size();

    for(int i = 1; i < len; i++){
        if(parent_list[i].anc == V2){
            int len2 = child_list[i].size();
            int control2 = 0;
            for(int j = 0; j < len2; j++){
                if(parent_list[child_list[i][j]].anc == V2){
                    control2 = 1;
                }
            }
            if(control2 == 0){
                cout << i << " ";
                control = 1;
            }
        }
    }


    if(control == 0){
        cout << "-";
    }
    cout << endl;
}


int main() {
    int v1, v2;
    scanf("%d %d", &v1, &v2);

    int nodes, edges;
    scanf("%d %d", &nodes, &edges);

    int parent, child;
    vector<node> parent_list (nodes + 1);
    vector<vector<int>> child_list (nodes + 1);
    
    for(int i = 0; i < edges; i++){
        scanf("%d %d", &parent, &child);
        int p_i = parent_list[child].p_i;
        if(p_i > 1){
            cout << "0" << endl;
            return 0;
        }
        parent_list[child].p[p_i] = parent;
        parent_list[child].p_i++;
        child_list[parent].push_back(child);
    }

    check(parent_list);

    closest_common_ancester(parent_list, child_list, v1, v2);
    

    //print_parent(parent_list, 8);

    return 0;
}