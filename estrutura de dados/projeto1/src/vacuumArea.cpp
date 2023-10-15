#include <queue>
#include <tuple>
#include <string>


int vacuumArea(std::string str_matrix, int m, int n, int x, int y) {
    using namespace std;

    // str matrix to array & zero array
    int** space;
    space = new int*[m];
    int** visited;
    visited = new int*[m];
    int count = 0;

    for (int i = 0; i < m; i++){
        space[i] = new int[n];
        visited[i] = new int[n];
        for (int j = 0; j < n; j++) {
            space[i][j] = str_matrix[count] - '0';
            visited[i][j] = 0;
            count++;
        }
    }

    // determining area with space components
    int area = 0;
    tuple<int, int> position;
    queue<tuple<int, int>> next_positions; 
    if (space[x][y] == 1) {
        next_positions.push(make_tuple(x, y));
        visited[x][y] = 1;
        area++;
    }
    
    while (next_positions.size()) {
        position = next_positions.front(); 
        next_positions.pop();
        int i = get<0>(position);
        int j = get<1>(position);
        
        if (i - 1 >= 0 && space[i - 1][j] == 1 && visited[i - 1][j] == 0) {
            next_positions.push(make_tuple(i - 1, j));
            visited[i - 1][j] = 1;
            area++;
        }
        if (i + 1 < m && space[i + 1][j] == 1 && visited[i + 1][j] == 0) {
            next_positions.push(make_tuple(i + 1, j));
            visited[i + 1][j] = 1;
            area++;
        }
        if (j - 1 >= 0 && space[i][j - 1] == 1 && visited[i][j - 1] == 0) {
            next_positions.push(make_tuple(i, j - 1));
            visited[i][j - 1] = 1;
            area++;
        }
        if (j + 1 < n && space[i][j + 1] == 1 && visited[i][j + 1] == 0) {
            next_positions.push(make_tuple(i, j + 1));
            visited[i][j + 1] = 1;
            area++;
        }
    }

    // dynamic matrixes delete
    for (int i = 0; i < m; i++){
        delete space[i];
        delete visited[i];
    }
    delete space;
    delete visited;

    return area;
}
