# Tên của chương trình thực thi sẽ được tạo ra
TARGET = readdir_program

# Tên của tệp nguồn C
SOURCES = readdir_file.c

# Trình biên dịch C
CC = gcc

# Các cờ biên dịch (compiler flags)
# -Wall: Bật tất cả các cảnh báo có thể
# -Wextra: Bật thêm một số cảnh báo bổ sung
# -std=c99: Sử dụng chuẩn C99
CFLAGS = -Wall -Wextra -std=c99

# Các cờ liên kết (linker flags) - nếu có thư viện ngoài cần liên kết
LDFLAGS =

# Quy tắc mặc định (default rule)
# Khi bạn chạy 'make' mà không chỉ định mục tiêu, nó sẽ chạy mục tiêu này
all: $(TARGET)

# Quy tắc để biên dịch chương trình thực thi
$(TARGET): $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) $(LDFLAGS) -o $(TARGET)

# Quy tắc để làm sạch (clean) các tệp được tạo ra
# Khi bạn chạy 'make clean', nó sẽ xóa các tệp này
clean:
	rm -f $(TARGET) *.o

# Quy tắc phony để khai báo các mục tiêu 'all' và 'clean' không phải là tệp
.PHONY: all clean
