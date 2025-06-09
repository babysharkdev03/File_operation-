#include <stdio.h> 
#include <dirent.h>
#include <sys/stat.h>
#include <time.h> 	
#include <string.h>
#include <stdlib.h>


int main() 
{
	char path[512];
	
	DIR *d = NULL; 
	
	while(1)
	{
		printf("Nhập đường dẫn thư mục (hoặc 'exit' để thoát):");
		fgets(path, sizeof(path), stdin); 
		path[strcspn(path, "\n")] = '\0'; // Xóa dấu newline 

		if (strcmp(path, "exit") == 0)
		{
			printf("Đã thoát.\n");
			return 0; 
		}

		d = opendir(path); 
		if (d == NULL)
		{
			perror("Không thể mở thư mục");
		}
		else{
			break; // mở được => tiếp tục 
		}

	}

	struct dirent *entry; 
/*	struct dirent {
 	 	ino_t          d_ino;       // inode number (ít dùng)
  	 	off_t          d_off;       // offset (ít dùng)
  	 	unsigned short d_reclen;    // length of this record
  	 	unsigned char  d_type;      // type of file (DT_REG, DT_DIR, v.v.)
	   	char           d_name[256]; // tên file/thư mục
	};*/
	char filepath[1000];
	struct stat sb; 
	while((entry = readdir(d)) != NULL) 
	{      	
		snprintf(filepath, 1000,"%s/%s", path, entry->d_name); 

		if(stat(filepath, &sb) == 0)
		{
			printf("Ten: %s | Size: %ld | Modify: %s", entry->d_name, sb.st_size, ctime(&sb.st_mtime));
		} 
	}

	
	closedir(d); 
	
}
