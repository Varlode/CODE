
def cau1():
    def unitMatrix(n):
        a = []
        for i in range(n):
            
            #Tạo list rỗng các giá trị = 0
            b = []
            for j in range(n):
                b.append(0)
                
            #Ô nằm trên đường chéo gán = 1
            b[i] = 1
            
            #Gán list vừa tạo vào matrix
            a.append(b)
        return a
    
    #In matrix
    for i in unitMatrix(int(input())):
        print(i)

def cau2():
    #Nhâp dữ liêu
    a = input().split()
    b = [] #List lưu các số đã gặp
    c = [] #List đếm số lần gặp
    
    for i in a:
        if i not in b:
            #Lưu thứ tự gặp từng số
            b.append(i)
            c.append(1)
        else:
            #Tìm vị trí số đã gặp để đếm số lần gặp
            c[b.index(i)] += 1
            
    #In kết quả
    for i in range(len(c)):
        print("Số " + str(b[i]) + " lặp lại " + str(c[i]) + " lần")

def cau3():
    n = int(input())
    hangnam = []
    for i in range(n):
        #Nhập dữ liệu 12 tháng
        tiendien = input().split() 
        tong = 0
        
        #Tính tổng 12 tháng
        for moithang in tiendien:
            tong += int(moithang)
            
        #Từ đó tính trung bình mỗi năm
        tiendien.append(tong / 12)
        
        #Thêm giá trị trung bình ở cuối list
        hangnam.append(tiendien)
    tong = 0
    for i in hangnam:
        print(i)
        
        #Lấy tổng các giá trị trung bình ở từng cuối list
        tong += i[len(i) - 1]
        
    #Tính trung bình các năm
    print(tong / n)

#Muốn thực hiện câu nào hãy gọi hàm câu đó
cau3()