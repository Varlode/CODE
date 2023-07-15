#Dùng thư viện math để dùng hàm max cũng như các hàm toán học
import math

def cau1():
    #Nhập dữ liệu
    danhSachTen = input().split()
    
    #Đếm số lần xuất hiện của từng số
    ten, dem = [], []
    for i in danhSachTen:
        if i not in ten:
            ten.append(i)
            dem.append(1)
        else:
            dem[ten.index(i)] += 1
    
    #In kết quả
    for i in range(len(ten)):
        print(ten[i], "xuất hiện", dem[i], "lần")
        
def cau2():
    #Nhâp dữ liệu
    n, m = [int(x) for x in input().split()]
    maTran = []
    
    #Nhập dữ liệu
    for i in range(m):
        maTran.append(input().split())
        
    #In ma trận
    print(x for x in maTran) 
    
    #Tính tổng và tìm max
    tongHang = []
    maxTong = 0
    tong = 0
    for i in maTran:
        tongMoiHang = 0
        for x in i:
            tongMoiHang += int(x)
        tongHang.append(tongMoiHang)
        maxTong = max(tongMoiHang, maxTong)
        tong += tongMoiHang
        
    print("Tổng là:", tong)
    
    #In các hàng có tổng lớn nhất
    for i in range(len(maTran)):
        if tongHang[i] == maxTong:
            print(maTran[i])
    
    #In các số đã xuất hiện và lưu vị trí của các số        
    daXuatHien, soLanXuatHien, viTri = [], [], []
    hang, cot = 0, 0
    print("Các số đã xuất hiện là: ")
    for i in maTran:
        cot = 0
        for j in i:
            if j not in daXuatHien:
                daXuatHien.append(j)
                soLanXuatHien.append(1)
                viTri.append([])
                print(j, end = " ")
            else:
                soLanXuatHien[daXuatHien.index(j)] += 1
            viTri[daXuatHien.index(j)].append([hang + 1, cot + 1])
            cot += 1
        hang += 1
    print()
    
    #Nhập dữ liệu và in ra vị trí số cần tìm
    x = input("Số bạn cần tìm là? ")
    print(x, "đã xuất hiện", soLanXuatHien[daXuatHien.index(x)], "lần tại:")
    print("Các [Hàng, Cột]:")
    for i in viTri[daXuatHien.index(x)]:
        print(i)
            
#Muốn thực hiện câu nào hãy gọi hàm câu đó
cau2()
