#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){

	DIR *d;
	struct dirent *entry;
	struct stat sb;

	d = opendir(".");
	entry = readdir(d);



	printf("Statistics for directory: .\n");


	int size = 0;
	while(entry != NULL){
		if(entry->d_type == DT_REG){
			stat(entry->d_name, &sb);
			size += sb.st_size;
		}
		if(entry->d_type == DT_DIR){
			printf("\t%s\n",entry->d_name);
		}
		entry = readdir(d);
	}

	printf("\nTotal Directory Size: %d Bytes\n\n", size);

	rewinddir(d);
	entry = readdir(d);

	printf("Regular files:\n");
	while(entry != NULL){
		if(entry->d_type == DT_REG){
			printf("\t%s\n", entry->d_name);
        	}
		entry = readdir(d);
	}

	closedir(d);
	return 0;
}
