#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int dinhThuc(vector<vector<int>> maTran, int n) {
    int det = 0;
    if (n == 1) {
        return maTran[0][0];
    }
    if (n == 2) {
        return (maTran[0][0] * maTran[1][1] - maTran[0][1] * maTran[1][0]);
    }
    vector<vector<int>> submatrix(n, vector<int>(n));
    for (int x = 0; x < n; x++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x)
                    continue;
                submatrix[subi][subj] = maTran[i][j];
                subj++;
            }
            subi++;
        }
        det = det + (pow(-1, x) * maTran[0][x] * dinhThuc(submatrix, n - 1));
    }
    return det;
}

int nghichDaoMod(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

string maHoaHill(string thongDiep, vector<vector<int>> khoa) {
    int n = khoa.size();
    while (thongDiep.size() % n != 0) {
        thongDiep += 'X'; 
    }

    string encrypted = "";
    for (size_t i = 0; i < thongDiep.size(); i += n) {
        vector<int> block(n);
        for (int j = 0; j < n; j++) {
            block[j] = thongDiep[i + j] - 'A';
        }

        vector<int> result(n, 0);
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                result[row] += khoa[row][col] * block[col];
            }
            result[row] %= 26;
        }

        for (int val : result) {
            encrypted += (val + 'A');
        }
    }

    return encrypted;
}

string giaiMaHill(string thongDiepMaHoa, vector<vector<int>> khoa) {
    int n = khoa.size();
    int det = dinhThuc(khoa, n);
    int detInv = nghichDaoMod(det % 26, 26);

    if (detInv == -1) {
        throw invalid_argument("Key matrix is not invertible.");
    }

    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vector<vector<int>> submatrix(n - 1, vector<int>(n - 1));
            for (int sub_i = 0, x = 0; sub_i < n; sub_i++) {
                if (sub_i == i) continue;
                for (int sub_j = 0, y = 0; sub_j < n; sub_j++) {
                    if (sub_j == j) continue;
                    submatrix[x][y] = khoa[sub_i][sub_j];
                    y++;
                }
                x++;
            }
            adj[j][i] = pow(-1, i + j) * dinhThuc(submatrix, n - 1);
            adj[j][i] = (adj[j][i] % 26 + 26) % 26;
        }
    }

    vector<vector<int>> inverseKey(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverseKey[i][j] = (adj[i][j] * detInv) % 26;
        }
    }

    string decrypted = "";
    for (size_t i = 0; i < thongDiepMaHoa.size(); i += n) {
        vector<int> block(n);
        for (int j = 0; j < n; j++) {
            block[j] = thongDiepMaHoa[i + j] - 'A';
        }

        vector<int> result(n, 0);
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                result[row] += inverseKey[row][col] * block[col];
            }
            result[row] %= 26;
        }

        for (int val : result) {
            decrypted += (val + 'A');
        }
    }

    return decrypted;
}

int main() {
    string thongDiep;
    cout << "Nhap thong diep can ma hoa: ";
    cin >> thongDiep;

    vector<vector<int>> khoa = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}};

    string thongDiepMaHoa = maHoaHill(thongDiep, khoa);
    cout << "Thong diep ma hoa: " << thongDiepMaHoa << endl;

    string thongDiepGiaiMa = giaiMaHill(thongDiepMaHoa, khoa);
    cout << "Thong diep giai ma: " << thongDiepGiaiMa << endl;

    return 0;
}