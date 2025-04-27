#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void chuanBiMaTranKhoa(string khoa, char maTranKhoa[5][5]) {
    vector<bool> daSuDung(26, false);
    daSuDung['J' - 'A'] = true;

    int hang = 0, cot = 0;
    for (char c : khoa) {
        if (c == 'J') c = 'I';
        if (!daSuDung[c - 'A']) {
            maTranKhoa[hang][cot++] = c;
            daSuDung[c - 'A'] = true;
            if (cot == 5) {
                cot = 0;
                hang++;
            }
        }
    }

    for (char c = 'A'; c <= 'Z'; c++) {
        if (!daSuDung[c - 'A']) {
            maTranKhoa[hang][cot++] = c;
            if (cot == 5) {
                cot = 0;
                hang++;
            }
        }
    }
}

string xuLyVanBanGoc(string vanBanGoc) {
    string processed = "";
    for (char c : vanBanGoc) {
        if (c == 'J') c = 'I';
        if (isalpha(c)) processed += toupper(c);
    }

    for (size_t i = 0; i < processed.length() - 1; i += 2) {
        if (processed[i] == processed[i + 1]) {
            processed.insert(i + 1, "X");
        }
    }

    if (processed.length() % 2 != 0) {
        processed += 'X';
    }

    return processed;
}

void timViTri(char kyTu, char maTranKhoa[5][5], int &hang, int &cot) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (maTranKhoa[i][j] == kyTu) {
                hang = i;
                cot = j;
                return;
            }
        }
    }
}

string maHoaCapKyTu(char a, char b, char maTranKhoa[5][5]) {
    int row1, col1, row2, col2;
    timViTri(a, maTranKhoa, row1, col1);
    timViTri(b, maTranKhoa, row2, col2);

    if (row1 == row2) {
        return string(1, maTranKhoa[row1][(col1 + 1) % 5]) + maTranKhoa[row2][(col2 + 1) % 5];
    } else if (col1 == col2) {
        return string(1, maTranKhoa[(row1 + 1) % 5][col1]) + maTranKhoa[(row2 + 1) % 5][col2];
    } else {
        return string(1, maTranKhoa[row1][col2]) + maTranKhoa[row2][col1];
    }
}

string giaiMaCapKyTu(char a, char b, char maTranKhoa[5][5]) {
    int row1, col1, row2, col2;
    timViTri(a, maTranKhoa, row1, col1);
    timViTri(b, maTranKhoa, row2, col2);

    if (row1 == row2) {
        return string(1, maTranKhoa[row1][(col1 + 4) % 5]) + maTranKhoa[row2][(col2 + 4) % 5];
    } else if (col1 == col2) {
        return string(1, maTranKhoa[(row1 + 4) % 5][col1]) + maTranKhoa[(row2 + 4) % 5][col2];
    } else {
        return string(1, maTranKhoa[row1][col2]) + maTranKhoa[row2][col1];
    }
}

string maHoa(string vanBanGoc, string khoa) {
    char maTranKhoa[5][5];
    chuanBiMaTranKhoa(khoa, maTranKhoa);
    vanBanGoc = xuLyVanBanGoc(vanBanGoc);

    string vanBanMaHoa = "";
    for (size_t i = 0; i < vanBanGoc.length(); i += 2) {
        vanBanMaHoa += maHoaCapKyTu(vanBanGoc[i], vanBanGoc[i + 1], maTranKhoa);
    }

    return vanBanMaHoa;
}

string giaiMa(string vanBanMaHoa, string khoa) {
    char maTranKhoa[5][5];
    chuanBiMaTranKhoa(khoa, maTranKhoa);

    string vanBanGoc = "";
    for (size_t i = 0; i < vanBanMaHoa.length(); i += 2) {
        vanBanGoc += giaiMaCapKyTu(vanBanMaHoa[i], vanBanMaHoa[i + 1], maTranKhoa);
    }

    return vanBanGoc;
}

int main() {
    string khoa, vanBanGoc, vanBanMaHoa;

    cout << "Nhap khoa: ";
    cin >> khoa;

    cout << "Nhap van ban goc: ";
    cin >> vanBanGoc;

    vanBanMaHoa = maHoa(vanBanGoc, khoa);
    cout << "Van ban ma hoa: " << vanBanMaHoa << endl;

    string vanBanGiaiMa = giaiMa(vanBanMaHoa, khoa);
    cout << "Van ban giai ma: " << vanBanGiaiMa << endl;

    return 0;
}