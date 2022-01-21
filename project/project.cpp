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
    int p_i = 0;
    int p[2];
} node;

void print_parent(vector<node> &parent_list, int nodes){
    // Parent List ----------------------------
    cout << "Parent List" << endl;
    int len2;
    for(int i = 1; i <= nodes; i++){
        len2 = parent_list[i].p_i;
        cout << i << " Color = " << parent_list[i].c << " --->";
        for(int j = 0; j < len2; j++){
            cout << " " << parent_list[i].p[j];
        }
        cout << endl;
    }
    cout << endl;
// ---------------------------------------
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


void dfs_visit(vector<node> &parent_list, int v, int color){
    int p_i = parent_list[v].p_i;
    parent_list[v].c = color;
    for(int i = 0; i < p_i; i++){
        int p = parent_list[v].p[i];
        if (parent_list[p].c == BLACK){
            dfs_visit(parent_list, p, color);
        } else if(parent_list[p].c != color){
            parent_list[p].c = WHITE;
        }
    }
}

void closest_common_ancester(vector<node> &parent_list, int v1, int v2){
    dfs_visit(parent_list, v1, V1);

    print_parent(parent_list, 8);

    dfs_visit(parent_list, v2, V2);
    int len = parent_list.size();
    for(int i = 1; i < len; i++){
        if(parent_list[i].c == WHITE){
        cout << i << " ";
        }
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
    
    for(int i = 0; i < edges; i++){
        scanf("%d %d", &parent, &child);
        int p_i = parent_list[child].p_i;
        if(p_i > 1){
            cout << "0" << endl;
            return 0;
        }
        parent_list[child].p[p_i] = parent;
        parent_list[child].p_i++;        
    }
    
    check(parent_list);

    closest_common_ancester(parent_list, v1, v2);
    

    print_parent(parent_list, 8);

    return 0;
}