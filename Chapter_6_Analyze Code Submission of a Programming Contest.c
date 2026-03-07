/*Data about submission of a programming contest consists a sequence of lines, each line has the following information:
                                      <UserID> <ProblemID> <TimePoint> <Status> <Point>
in which the user <UserID> submits his/her code to solve the problem <ProblemID> at time-point <TimePoint>, and gets status <Status> and point <Point>
<UserID>: string of length from 3 to 10
<ProblemID>: string under the format Pxy where x, y are digits 0,1,...,9 (for example P03, P10)
<TimePoint>: string representing time-point with the format HH:MM:SS (for example, 09:45:20 means the time-point 9 hour 45 minutes 20 seconds)
<Status>: string with two cases (ERR, OK)
<Point>: integer from {0, 1, 2, ..., 10}

A user can submit the code for solving each problem several time. The point that the user gets for a problem is the maximal point among the submissions for that problem.

Perform a sequence of queries of following types:
?total_number_submissions: return the number of submissions of the contest
?number_error_submision: return the number of submissions having status ERR 
?number_error_submision_of_user <UserID>: return the number of submission having status ERR of user <UserID> 
?total_point_of_user <UserID>: return the total point of user <UserID> 
?number_submission_period <from_time_point> <to_time_point>: return the number of submissions in the period from <from_time_point> to <to_time_point> (inclusive)

Input
The input consists of two blocks of data:
The first block is the operational data, which is a sequence of lines (number of lines can be up to 100000), each line contains the information of a submission with above format .The first block is terminated with a line containing the character #
The second block is the query block, which is a sequence of lines (number of lines can be up to 100000), each line is a query described above. The second block is terminated with a line containing the character #

Output
Write in each line, the result of the corresponding query */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxlen 100000

typedef struct inf{
    char userid[11];
    char problemid[4];
    char timepoint[12];
    char status[4];
    int point;
} inf;

typedef struct total{
    char userid[11];
    int totalpoint;
} total;

int cmp(const void* ptr1, const void* ptr2){
    inf* x = (inf*)ptr1;
    inf* y = (inf*)ptr2;
    return strcmp(x->timepoint, y->timepoint);
}

int cmpmax(const void* ptr1, const void* ptr2){
    inf* x = (inf*)ptr1;
    inf* y = (inf*)ptr2;
     int c = strcmp(x->userid, y->userid);
    if(c != 0) return c;
    c = strcmp(x->problemid, y->problemid);
    if(c != 0) return c;
    // So sánh điểm giảm dần để điểm max đứng đầu mỗi nhóm
    if(x->point > y->point) return -1;
    else if(x->point < y->point) return 1;
    else return 0;
}

int bs_user(total* a, int n, const void* key){
    int l = 0, r = n-1;
    while(l<=r){
        int m = (l+r)/2;
        int c = strcmp(a[m].userid, key);
        if(c == 0) return m;
        else if(c<0) l=m+1;
        else r=m-1;
    }
    return -1;
}

int lower_bound(inf* a, int n, const void* key){
    int l = 0, r = n-1;
    while(l<r){
        int m = (l+r)/2;
        if(strcmp(a[m].timepoint, key) < 0) l = m + 1;
        else r = m;
    }
    return l;
}

int upper_bound(inf* a, int n, const char* key){
    int l = 0, r = n-1;
    while(l<r){
        int m = (l+r)/2;
        if(strcmp(a[m].timepoint, key) <= 0) l = m + 1;
        else r = m;
    }
    return l;
}

int main(){
    inf *a = (inf*)malloc(maxlen*sizeof(inf));
    total *b = (total*)malloc(maxlen*sizeof(total));
    char c[100];
    int n=0;
    int foundmax = 0, cntprob = 0, foundtime = 0;
    while(1){
        if(!fgets(c, sizeof(c), stdin)) break;
        c[strcspn(c, "\n\r")] = '\0';
        if(strcmp(c, "#") == 0) break;
        sscanf(c, "%s %s %s %s %d", a[n].userid, a[n].problemid, a[n].timepoint, a[n].status, &a[n].point);
        n++;
    }
    while(1){
        if(!fgets(c, sizeof(c), stdin)) break;
        c[strcspn(c, "\n\r")] = '\0';
        if(strcmp(c, "#") == 0) break;
        if(strcmp(c, "?total_number_submissions") == 0) printf("%d\n", n);
        else if(strcmp(c, "?number_error_submision") == 0){
            int cnterr = 0;
            for(int i=0; i<n; i++){
                if(strcmp(a[i].status, "ERR") == 0) cnterr++;
            }
            printf("%d\n", cnterr);
        }
        else if(strncmp(c, "?number_error_submision_of_user ", 32) == 0){
            int cntusererr = 0;
            char usererr[11];
            sscanf(c+32, "%s", usererr);
            for(int i=0; i<n; i++){
                if(strcmp(usererr, a[i].userid) == 0 && strcmp(a[i].status, "ERR") == 0) cntusererr++;
            }
            printf("%d\n", cntusererr);
        }
        else if(strncmp(c, "?total_point_of_user ", 21) == 0){//qsort trước lần lượt userid và problem id sau đó đưa dữ liệu user với max point vào bảng khác
            int sumuser = 0;
            char usersum[11];
            sscanf(c+21, "%s", usersum);
            if(!foundmax){
                qsort(a, n, sizeof(inf), cmpmax);
                for(int i=0; i<n; i++){
                    if(i == 0 || strcmp(a[i].userid, a[i-1].userid) != 0){
                        strcpy(b[cntprob].userid, a[i].userid);
                        b[cntprob].totalpoint = 0;  
                        cntprob ++;
                    }
                    if(i == 0 || strcmp(a[i].userid, a[i-1].userid) != 0 || strcmp(a[i].problemid, a[i-1].problemid) != 0){
                            b[cntprob-1].totalpoint += a[i].point;
                        }
                }
                foundmax = 1;
            }
            int idx = bs_user(b, cntprob, usersum);
            if(idx == -1) sumuser = 0;
            else sumuser = b[idx].totalpoint;
            printf("%d\n", sumuser);
        }
        // else if(strncmp(c, "?total_point_of_user ", 21) == 0){ //Thời gian lâu vì phải chạy 2 vòng lặp lồng nhau
        //     int sumuser = 0;
        //     char usersum[11];
        //     total *b = (total*)malloc(maxlen*sizeof(total));
        //     int cntprob = 0;
        //     sscanf(c+21, "%s", usersum);
        //     for(int i=0; i<n; i++){
        //         if(strcmp(usersum, a[i].userid) == 0){
        //             int found = 0;
        //             for(int j=0; j<cntprob; j++){
        //                 if(strcmp(a[i].problemid, b[j].problemid) == 0){
        //                     if(b[j].point < a[i].point) b[j].point = a[i].point;
        //                     found = 1;
        //                     break;
        //                 }
        //             }
        //             if(!found){
        //                     strcpy(b[cntprob].problemid, a[i].problemid);
        //                     b[cntprob].point = a[i].point;
        //                     cntprob++;
        //                 }
        //         }
        //     } 
        //     for(int i=0; i<cntprob; i++) sumuser += b[i].point;
        //     printf("%d\n", sumuser);
        // }
        // else if(strncmp(c, "?number_submission_period ", 26) == 0){ //Bị time out do độ phức tạp là O(n*q)
        //     char start[11], end[11];
        //     int cnttime = 0;
        //     sscanf(c+26, "%s %s", start, end);
        //     for(int i=0; i<n; i++){
        //         if(strcmp(a[i].timepoint, start) >= 0 && strcmp(a[i].timepoint, end) <= 0){
        //             cnttime++;
        //         }
        //     }
        //     printf("%d\n", cnttime);
        // }
        else if(strncmp(c, "?number_submission_period ", 26) == 0){//Dùng binary search
            if(!foundtime) {
                qsort(a, n, sizeof(inf), cmp);
                foundtime = 1;
            }
            char start[12], end[12];
            int cnttime = 0;
            sscanf(c+26, "%s %s", start, end);
            printf("%d\n", upper_bound(a, n, end) - lower_bound(a, n, start));
        }
    }
}