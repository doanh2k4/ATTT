#include <iostream>
#include <string>
#include <vector>

using namespace std;

string maHoaRainFence(const string &vanBan, int soHang) {
    vector<string> hang(soHang);
    int huong = 1; 
    int dong = 0;

    for (char kyTu : vanBan) {
        hang[dong] += kyTu;
        dong += huong;

        if (dong == 0 || dong == soHang - 1) {
            huong *= -1;
        }
    }

    string vanBanMaHoa;
    for (const string &h : hang) {
        vanBanMaHoa += h;
    }

    return vanBanMaHoa;
}

string giaiMaRainFence(const string &vanBanMaHoa, int soHang) {
    vector<int> doDaiHang(soHang, 0);
    int huong = 1;
    int dong = 0;

    for (int i = 0; i < vanBanMaHoa.size(); ++i) {
        doDaiHang[dong]++;
        dong += huong;

        if (dong == 0 || dong == soHang - 1) {
            huong *= -1;
        }
    }

    vector<string> hang(soHang);
    int chiSo = 0;
    for (int i = 0; i < soHang; ++i) {
        hang[i] = vanBanMaHoa.substr(chiSo, doDaiHang[i]);
        chiSo += doDaiHang[i];
    }

    string vanBanGiaiMa;
    dong = 0;
    huong = 1;
    vector<int> chiSoHang(soHang, 0);

    for (int i = 0; i < vanBanMaHoa.size(); ++i) {
        vanBanGiaiMa += hang[dong][chiSoHang[dong]++];
        dong += huong;

        if (dong == 0 || dong == soHang - 1) {
            huong *= -1;
        }
    }

    return vanBanGiaiMa;
}

int main() {
    string vanBan;
    int soHang;

    cout << "Nhap van ban: ";
    getline(cin, vanBan);

    cout << "Nhap so hang: ";
    cin >> soHang;
    cin.ignore();

    string vanBanMaHoa = maHoaRainFence(vanBan, soHang);
    cout << "Van ban ma hoa: " << vanBanMaHoa << endl;

    string vanBanGiaiMa = giaiMaRainFence(vanBanMaHoa, soHang);
    cout << "Van ban giai ma: " << vanBanGiaiMa << endl;

    return 0;
}