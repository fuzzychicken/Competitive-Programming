#include <bits/stdc++.h>
using namespace std;

struct PT {
	int r1, r2, c1, c2;
};

int n, pcl_size;
char grid[20][20];
bool vis[20][20];
vector<PT> potential_pcl;

void floodfill2(int x, int y, int color, int r1, int c1, int r2, int c2) {
	//if (x <= r1 || x >= r2 || y <= c1 || y >= c1 || grid[x][y]-'A' != color || vis[x][y]) return;
	vis[x][y] = true;

	if (x > r1 && grid[x-1][y]-'A' == color && !vis[x-1][y]) 
		floodfill2(x-1, y, color, r1, c1, r2, c2);
	if (x < r2 && grid[x+1][y]-'A' == color && !vis[x+1][y]) 
		floodfill2(x+1, y, color, r1, c1, r2, c2);
	if (y > c1 && grid[x][y-1]-'A' == color && !vis[x][y-1]) 
		floodfill2(x, y-1, color, r1, c1, r2, c2);
	if (y < c2 && grid[x][y+1]-'A' == color && !vis[x][y+1]) 
		floodfill2(x, y+1, color, r1, c1, r2, c2);
}

void floodfill(char color, int r1, int r2, int c1, int c2, int x, int y) {
	if (x < r1 || x > r2 || y < c1 || y > c1 || grid[x][y] != color || vis[x][y]) return;
	vis[x][y] = true;
	floodfill(color, r1, r2, c1, c2, x-1, y);
	floodfill(color, r1, r2, c1, c2, x+1, y);
	floodfill(color, r1, r2, c1, c2, x, y+1);
	floodfill(color, r1, r2, c1, c2, x, y-1);
	//if (x > r1 && grid[x-1][y]==color && !vis[x-1][y]) 
		//floodfill(color,r1,r2,c1,c2,x-1,y);
	//if (x <r2 && grid[x+1][y]==color && !vis[x+1][y]) 
		//floodfill(color,r1,r2,c1,c2,x+1,y);
	//if (y > c1 && grid[x][y-1]==color && !vis[x][y-1]) 
		//floodfill(color,r1,r2,c1,c2,x,y-1);
	//if (y < c2 && grid[x][y+1]==color && !vis[x][y+1]) 
		//floodfill(color,r1,r2,c1,c2, x+1,y);
}

bool is_pcl(int r1, int r2, int c1, int c2) {
	//set<char> colors;
	//for (int i = row1; i <= row2; i++) {
		//for (int j = col1; j <= col2; j++) { 
			//colors.insert(grid[i][j]);
		//}
	//}
	//if (colors.size() != 2) {
		//return false;
	//}
	//cout << "DIMENSIONS:  " << row1 << ' ' << row2 << ' ' << col1 << ' ' << col2 << '\n';
	//char color1 = *colors.begin();
	//char color2 = *colors.rbegin();
	//cout << color1 << ' ' << color2 << '\n';
	//int cont_region_1 = 0;
	//int cont_region_2 = 0;
	//memset(vis, false, sizeof(vis));
	//for (int x = row1; x <= row2; x++) {
		//for (int y = col1; y <= col2; y++) {
			//if (!vis[x][y] && (grid[x][y] == color1)) {
				//floodfill(color1, row1, row2, col1, col2, x, y);
				//cont_region_1++;
			//}
		//}
	//}
	//memset(vis, false, sizeof(vis));
	//for (int x = row1; x <= row2; x++) {
		//for (int y = col1; y <= col2; y++) {
			//if (!vis[x][y] && (grid[x][y] == color2)) {
				//floodfill(color2, row1, row2, col1, col2, x, y);
				//cont_region_2++;
			//}
		//}
	//}
	//cout << cont_region_1 << " " << cont_region_2 << '\n';
	//if (cont_region_1 == 1 || cont_region_2 == 1) {
		//if (cont_region_1 >= 2 || cont_region_2 >= 2) {
			//cout << "GOOD PCL\n";
			//return true;
		//}
	//}
	//return false;
	int num_colors = 0;
	int color_count[26] = {0};
	for (int i = r1; i <= r2; i++)
		for (int j = c1; j <= c2; j++)
			vis[i][j] = false;
	for (int i = r1; i <= r2; i++)
		for (int j = c1; j <= c2; j++)
			if (!vis[i][j]) {
				int c = grid[i][j] - 'A';
				if (color_count[c] == 0) num_colors++;
				color_count[c]++;
				floodfill2(i,j,c,r1,c1,r2,c2);
			}
	if (num_colors != 2) return false;
	bool found_one = false, found_many = false;
	for (int i = 0; i < 26; i++) {
		if (color_count[i] == 1) found_one = true;
		if (color_count[i] > 1) found_many = true;
	}
	return found_one && found_many;
}

bool pcl_within(int x, int y) {
	return potential_pcl[x].r1 >= potential_pcl[y].r1
			&& potential_pcl[x].r2 <= potential_pcl[y].r2
			&& potential_pcl[x].c1 >= potential_pcl[y].c1
			&& potential_pcl[x].c2 <= potential_pcl[y].c2;
}

bool pcl_good(int x) {
	for (int i = 0; i < pcl_size; i++) {
		if (i != x && pcl_within(x, i)) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen("where.in","r",stdin);
	freopen("where.out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	for (int row1 = 0; row1 < n; row1++) {
		for (int col1 = 0; col1 < n; col1++) {
			for (int row2 = row1; row2 < n; row2++) {
				for (int col2 = col1; col2 < n; col2++) {
					if (is_pcl(row1, row2, col1, col2) ) {
						potential_pcl.push_back({row1, row2, col1, col2});
						pcl_size++;
					}
				}
			}
		}
	}
	int num_pcl = 0;
	for (int i = 0; i < pcl_size; i++) {
		if (pcl_good(i)) {
			num_pcl++;
		}
	}
	cout << num_pcl << '\n';
	return 0;
}
