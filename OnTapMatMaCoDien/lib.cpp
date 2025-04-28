// ###### CAESAR ######

//============================
#include <iostream>
using namespace std;

int main(){
    string p = "trungvu", c = "", dec = "";
    int k = 9;
    for(int i = 0; i < p.size(); i++){
        c += (char)(((p[i] - 'a') + k) % 26 + 'a');
    }
    cout << "Chuoi ma hoa: " << c << endl;

    for(int i = 0; i < c.size(); i++){
        dec += (char)(((c[i] - 'a') - k + 26) % 26 + 'a');
    }
    cout << "Chuoi giai ma: " << dec << endl;
}
//=============================

#include <iostream>
#include <string>

using namespace std;

int KT_So(char c) {
    return c - 'a';
}

char So_KT(int n) {
    return 'a' + n;
}

int main() {
    string p, c;
    int k;
    cout << "Nhap chuoi Plaintext: ";
    cin >> p;
    cout << "Nhap K: ";
    cin >> k;

    // Ma hoa
    for (int i = 0; i < p.size(); i++) {
        int m = (KT_So(p[i]) + k) % 26;
        c += So_KT(m);
    }
    cout << "Chuoi ma hoa: " << c << endl;

    // Giai ma
    p = "";
    for (int i = 0; i < c.size(); i++) {
        int m = (KT_So(c[i]) - k + 26) % 26; // +26 để xử lý trường hợp số âm
        p += So_KT(m);
    }
    cout << "Chuoi giai ma: " << p;

    return 0;
}

//crute force caesar

#include <iostream>
#include <string>
#include <cctype> // Cho isalpha, isupper, tolower

using namespace std;

string caesar_decrypt(const string& ciphertext, int key) {
    string plaintext = "";
    for (char ch : ciphertext) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            plaintext += (char)(((ch - base - key) % 26 + 26) % 26 + base);
        } else {
            plaintext += ch;
        }
    }
    return plaintext;
}

int main() {
    string c;

    cout << "Nhap chuoi Ciphertext: ";
    getline(cin, c); // Dùng getline

    for (int k = 1; k < 26; k++) {
        cout << k << ": " << caesar_decrypt(c, k) << endl;
    }

    return 0;
}


// ###### AFFINE ######

#include <iostream>
#include <string>

using namespace std;

int KT_So(char c) {
    return c - 'A';
}

char So_KT(int n) {
    return 'A' + n;
}

int main() {
    string p, c;
    int a, b;

    cout << "Nhap chuoi Plaintext: ";
    cin >> p;

    do {
        cout << "Nhap khoa a: ";
        cin >> a;
    } while (a % 2 == 0 || a == 13);

    cout << "Nhap khoa b: ";
    cin >> b;

    // Ma hoa
    for (int i = 0; i < p.size(); i++) {
        int m = (a * KT_So(p[i]) + b) % 26;
        c += So_KT(m);
    }
    cout << "Chuoi ma hoa: " << c << endl;

    // Giai ma
    p = "";
    int a1;
    for (int i = 1; i < 26; i += 2) {
        if (i * a % 26 == 1) {
            a1 = i;
            break;
        }
    }

    for (int i = 0; i < c.size(); i++) {
        int m = a1 * (KT_So(c[i]) - b + 26) % 26;
        p += So_KT(m);
    }
    cout << "Chuoi giai ma: " << p;

    return 0;
}

// bruce force affine
#include <iostream>
#include <string>

using namespace std;

int KT_So(char c) {
    return c - 'A';
}

char So_KT(int n) {
    return 'A' + n;
}

int main() {
    string p, c;
    int a, b;

    cout << "Nhap chuoi Ciphertext: ";
    cin >> c;

    for (a = 1; a < 26; a += 2) {
        if (a != 13) {
            for (b = 0; b < 26; b++) {
                p = "";
                int a1;
                for (int i = 1; i < 26; i += 2) {
                    if (i * a % 26 == 1) {
                        a1 = i;
                        break;
                    }
                }

                for (int i = 0; i < c.size(); i++) {
                    int m = a1 * (KT_So(c[i]) - b + 26) % 26;
                    p += So_KT(m);
                }
                cout << "[" << a << "," << b << "]: " << p << endl;
            }
        }
    }

    return 0;
}


// ###### PLAYFAIR ######
#include <iostream>
#include <cstring>

using namespace std;

#define SIZE 5

char keyMatrix[SIZE][SIZE];

// Loại bỏ ký tự trùng lặp trong khóa
void removeDuplicates(char key[], char newKey[]) {
    int len = strlen(key);
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (strchr(newKey, key[i]) == NULL) {
            newKey[index++] = key[i];
        }
    }
    newKey[index] = '\0';
}

// Tạo ma trận khóa Playfair
void createKeyMatrix(char key[]) {
    char alphabet[] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    char temp[26] = "";
    removeDuplicates(key, temp);
    
    for (int i = 0; i < strlen(temp); i++) {
        char *pos = strchr(alphabet, temp[i]);
        if (pos) *pos = ' ';
    }
    strcat(temp, alphabet);
    
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            while (temp[index] == ' ') index++;
            keyMatrix[i][j] = temp[index++];
        }
    }
}

// Tìm vị trí của ký tự trong ma trận khóa
void findPosition(char ch, int &row, int &col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (keyMatrix[i][j] == ch) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

// Mã hóa Playfair
void playfairEncrypt(char text[]) {
    int len = strlen(text);
    for (int i = 0; i < len; i += 2) {
        int row1, col1, row2, col2;
        findPosition(text[i], row1, col1);
        findPosition(text[i + 1], row2, col2);
        
        if (row1 == row2) {
            text[i] = keyMatrix[row1][(col1 + 1) % SIZE];
            text[i + 1] = keyMatrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            text[i] = keyMatrix[(row1 + 1) % SIZE][col1];
            text[i + 1] = keyMatrix[(row2 + 1) % SIZE][col2];
        } else {
            text[i] = keyMatrix[row1][col2];
            text[i + 1] = keyMatrix[row2][col1];
        }
    }
}

// Giải mã Playfair
void playfairDecrypt(char text[]) {
    int len = strlen(text);
    for (int i = 0; i < len; i += 2) {
        int row1, col1, row2, col2;
        findPosition(text[i], row1, col1);
        findPosition(text[i + 1], row2, col2);
        
        if (row1 == row2) {
            text[i] = keyMatrix[row1][(col1 + 4) % SIZE];
            text[i + 1] = keyMatrix[row2][(col2 + 4) % SIZE];
        } else if (col1 == col2) {
            text[i] = keyMatrix[(row1 + 4) % SIZE][col1];
            text[i + 1] = keyMatrix[(row2 + 4) % SIZE][col2];
        } else {
            text[i] = keyMatrix[row1][col2];
            text[i + 1] = keyMatrix[row2][col1];
        }
    }
}

int main() {
    char key[50], text[100];
    cout << "Nhap tu khoa: ";
    cin >> key;
    
    for (int i = 0; key[i]; i++) {
        if (key[i] == 'J') key[i] = 'I';
    }
    createKeyMatrix(key);
    
    cout << "Nhap chuoi can ma hoa: ";
    cin >> text;
    
    if (strlen(text) % 2 != 0) strcat(text, "X");
    
    playfairEncrypt(text);
    cout << "Chuoi ma hoa: " << text << endl;
    
    playfairDecrypt(text);
    cout << "Chuoi giai ma: " << text << endl;
    
    return 0;
}

// ###### VERNMAN ######

#include <iostream>
#include <string>
using namespace std;

int main() {
    string p, c;
    char k;
    cout << "Nhap chuoi Plaintext: "; getline(cin, p);
    cout << "Nhap khoa K: "; cin >> k;
    c = p;

    // Ma hoa
    for(int i = 0; i < p.size(); i++) {
        c[i] = p[i] ^ k;
    }
    cout << "Chuoi ma hoa: " << c << endl;

    // Giai ma
    for(int i = 0; i < c.size(); i++) {
        p[i] = c[i] ^ k;
    }
    cout << "Chuoi giai ma: " << p << endl;

    return 0;
}

// ###### VIGENERE ######
#include <iostream>
#include <string>
using namespace std;

// Convert character to number (A=0, B=1, ..., Z=25)
int KT_So(char c) {
    return c - 'A';
}

// Convert number to character (0=A, 1=B, ..., 25=Z)
char So_KT(int n) {
    return 'A' + n;
}

int main() {
    string p, c, k;
    cout << "Nhap chuoi Plaintext: "; cin >> p;
    cout << "Nhap chuoi khoa K: "; cin >> k;

    // Ma hoa
    int j = 0;
    for(int i = 0; i < p.size(); i++) {
        int m = (KT_So(p[i]) + KT_So(k[j])) % 26;
        c += So_KT(m);
        j++;
        if(j == k.size()) {
            j = 0;
        }
    }
    cout << "Chuoi ma hoa: " << c << endl;

    // Giai ma
    j = 0;
    p = "";
    for(int i = 0; i < c.size(); i++) {
        int m = (KT_So(c[i]) - KT_So(k[j]) + 26) % 26;
        p += So_KT(m);
        j++;
        if(j == k.size()) {
            j = 0;
        }
    }
    cout << "Chuoi giai ma: " << p << endl;

    return 0;
}



// ###### HILL ######
#include <iostream>
#include <vector>

using namespace std;

//chuyen ki tu thanh so
int char_int(char c) {
	return c - 'A';
}
	
//chuyen so thanh ki tu
char int_char(int n){
	return 'A' + n;
}

// Tinh dinh thuc cua ma tran 3x3 theo 26 26
int det3x3(int K[3][3]) {
    int det = K[0][0] * (K[1][1] * K[2][2] - K[1][2] * K[2][1])
            - K[0][1] * (K[1][0] * K[2][2] - K[1][2] * K[2][0])
            + K[0][2] * (K[1][0] * K[2][1] - K[1][1] * K[2][0]);
    return (det % 26 + 26) % 26;
}

// Ham tim nghich dao cua dinh thuc theo mod 26
int modInverse(int det) {
    for (int i = 1; i < 26; i++) {
        if ((det * i) % 26 == 1)
            return i;
    }
    return -1;  // Khong co nghich dao
}

// Ham tim ma tran nghich dao cua kh�a 3x3 theo mod 26
bool inverseMatrix3x3(int K[3][3], int invK[3][3]) {
    int det = det3x3(K);
    int detInv = modInverse(det);
    if (detInv == -1) {
        cout << "Ma tran khoa khong co nghich dao, khong the giai ma!\n";
        return false;
    }

    // Tinh ma tran phu hop
    int adj[3][3];
    adj[0][0] = (K[1][1] * K[2][2] - K[1][2] * K[2][1]) % 26;
    adj[0][1] = -(K[0][1] * K[2][2] - K[0][2] * K[2][1]) % 26;
    adj[0][2] = (K[0][1] * K[1][2] - K[0][2] * K[1][1]) % 26;
    adj[1][0] = -(K[1][0] * K[2][2] - K[1][2] * K[2][0]) % 26;
    adj[1][1] = (K[0][0] * K[2][2] - K[0][2] * K[2][0]) % 26;
    adj[1][2] = -(K[0][0] * K[1][2] - K[0][2] * K[1][0]) % 26;
    adj[2][0] = (K[1][0] * K[2][1] - K[1][1] * K[2][0]) % 26;
    adj[2][1] = -(K[0][0] * K[2][1] - K[0][1] * K[2][0]) % 26;
    adj[2][2] = (K[0][0] * K[1][1] - K[0][1] * K[1][0]) % 26;

    // Tinh ma tran nghich dao
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            invK[i][j] = ((adj[i][j] * detInv) % 26 + 26) % 26;

    return true;
}

// Ma hoa
string encrypt(string P, int K[3][3]) {
    string C = "";

    // Dam bao do dai van ban %3
    while (P.length() % 3 != 0)
        P += 'X';

    for (int i = 0; i < P.length(); i += 3) {
        int p1 = char_int(P[i]);
        int p2 = char_int(P[i + 1]);;
        int p3 = char_int(P[i + 2]);;

        int c1 = (K[0][0] * p1 + K[0][1] * p2 + K[0][2] * p3) % 26;
        int c2 = (K[1][0] * p1 + K[1][1] * p2 + K[1][2] * p3) % 26;
        int c3 = (K[2][0] * p1 + K[2][1] * p2 + K[2][2] * p3) % 26;

        C += int_char(c1);
        C += int_char(c2);
        C += int_char(c3);
    }

    return C;
}

// Giai ma
string decrypt(string C, int K[3][3]) {
    string P = "";
    int invK[3][3];

    if (!inverseMatrix3x3(K, invK))
        return "";

    for (int i = 0; i < C.length(); i += 3) {
        int c1 = char_int(C[i]);
        int c2 = char_int(C[i + 1]);
        int c3 = char_int(C[i + 2]);

        int p1 = (invK[0][0] * c1 + invK[0][1] * c2 + invK[0][2] * c3) % 26;
        int p2 = (invK[1][0] * c1 + invK[1][1] * c2 + invK[1][2] * c3) % 26;
        int p3 = (invK[2][0] * c1 + invK[2][1] * c2 + invK[2][2] * c3) % 26;

        P += int_char(p1);
        P += int_char(p2);
        P += int_char(p3);
    }

    return P;
}

int main() {
    int K[3][3];
    string P;
	
	cout << "Nhap ma tran khoa K: " << endl; 
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++) {
			cout << "K[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> K[i][j];
		}
	}
	
    cout << "Nhap van ban (chu cai viet hoa, khong dau): ";
    cin >> P;

    string C = encrypt(P, K);
    cout << "Van ban da ma hoa: " << C << endl;

    string decryptedText = decrypt(C, K);
    cout << "Van ban giai ma: " << decryptedText << endl;

    return 0;
}

// ###### MONOALPHABETIC ######

#include <iostream>
#include <string>

using namespace std;

int main() {
    string p, c, k;
    string b = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    cout << "Nhap chuoi Plaintext: ";
    cin >> p;

    c = p; // Khởi tạo chuỗi mã hóa bằng chuỗi gốc

    cout << "Nhap chuoi khoa K: ";
    cin >> k;


    // Ma hoa
    for (int i = 0; i < p.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (p[i] == b[j]) {
                c[i] = k[j % k.size()]; // Thay thế bằng ký tự tương ứng trong khóa
                break;
            }
        }
    }
    cout << "Chuoi ma hoa: " << c << endl;

    // Giai ma
    for (int i = 0; i < c.size(); i++) {
        for (int j = 0; j < k.size(); j++) {
            if (c[i] == k[j]) {
                 p[i] = b[j];
                break;
            }
        }
    }
    cout << "Chuoi giai ma: " << p;

    return 0;
}


// ###### RAIN_FENCE ######

#include <iostream>
#include <string>
using namespace std;

int main() {
    string p, c, c1, c2;

    // Nhập chuỗi cần mã hóa
    cout << "Nhap chuoi Plaintext: ";
    getline(cin, p);

    // ========================
    //          Mã hóa
    // ========================
    c1 = c2 = "";
    for (int i = 0; i < p.size(); i++) {
        if (i % 2 == 0) {
            c1 += p[i];
        } else {
            c2 += p[i];
        }
    }
    c = c1 + c2;

    cout << "Chuoi ma hoa: " << c << endl;

    // ========================
    //          Giải mã
    // ========================
    int n;
    c1 = "";
    c2 = "";
    p = "";

    // Xác định vị trí phân chia 2 hàng (trong trường hợp chuỗi lẻ)
    if (c.size() % 2 == 0) {
        n = 0;
    } else {
        n = 1;
    }

    // Tách chuỗi c thành c1 và c2
    for (int i = 0; i < c.size(); i++) {
        if (i < c.size() / 2 + n) {
            c1 += c[i];
        } else {
            c2 += c[i];
        }
    }

    // Ghép lại theo thứ tự zigzag
    for (int i = 0; i < c.size() / 2; i++) {
        p += c1[i];
        p += c2[i];
    }

    // Nếu chuỗi ban đầu có độ dài lẻ, thêm ký tự cuối từ c1
    if (n == 1) {
        p += c1[c1.size() - 1];
    }

    cout << "Chuoi giai ma: " << p << endl;

    return 0;
}

// ###### HOANVI ######
#include <iostream>
#include <string>
using namespace std;

int main() {
    string p, c;
    char a[5][5];

    // Nhập chuỗi và loại bỏ khoảng trắng
    cout << "Nhap chuoi Plaintext: ";
    getline(cin, p);
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == ' ') {
            p.erase(i, 1);
            i--;
        }
    }

    // ========================
    //         Mã hóa
    // ========================
    int d = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (d < p.size()) {
                a[i][j] = p[d];
            } else {
                a[i][j] = 'X';  // Ký tự đệm nếu thiếu
            }
            d++;
            // a[i][j] = p[d];
            // d++;
            // if (d >= p.size()) {
            //     a[i][j] = 'X';  // Ký tự đệm nếu thiếu
            // }
        }
    }

    // Hiển thị ma trận
    cout << "\nMa tran hoan vi:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // Đọc theo cột để tạo ciphertext
    c = "";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            c += a[j][i];
        }
    }

    cout << "\nChuoi ma hoa: " << c << endl;

    // ========================
    //        Giải mã
    // ========================
    d = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // if (d < c.size()) {
            //     a[j][i] = c[d];
            // }
            // d++;
            a[j][i] = c[d];
            d++;
            if (d >= c.size()) {
                d=0;
            }
        }
    }

    // Đọc theo hàng để khôi phục plaintext
    p = "";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            p += a[i][j];
        }
    }

    cout << "Chuoi giai ma: " << p << endl;

    return 0;
}



// ###### số lần xuất hiện ký tự trong xâu ######

#include <iostream>
#include <string>

using namespace std;

int main() {
    string n;
    getline(cin, n); // Nhập cả dòng, bao gồm khoảng trắng

    // Xoa cac ki tu trung
    for (int i = 0; i < n.length() - 1; i++) {
        for (int j = i + 1; j < n.length(); j++) {
            if (n[i] == n[j]) {
                n.erase(j, 1);
                j--; // Giảm j vì đã xóa một phần tử
            }
        }
    }
    string temp = n; // Tạo một bản sao của chuỗi sau khi xóa, để đếm
    // Dem so lan xuat hien
   
    for (int i = 0; i < n.length(); i++) {
        int count = 0;
        for (int j = 0; j < temp.length(); j++) {
            if (n[i] == temp[j]) {
                count++;
            }
        }
        cout << n[i] << " " << count << endl;
    }

    return 0;
}