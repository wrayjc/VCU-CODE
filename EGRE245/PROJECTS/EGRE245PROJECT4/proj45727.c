/* 	Project #4
	EGRE245 Spring 2015
	JOHN C. WRAY */

#include <stdio.h>
#include <math.h>

int main(void) {
    int studentid=1, s1, s2, s3, s4,s5,s6,s7,s8,result,testers,error1,error2,error3,error4,error5,sa,sb,totalscores=0;
    float sum=0, average;
	printf("Proj. #4 - JOHN C. WRAY\n");
    
    printf("\n\nStudent Please Enter I.D. and enter scores:\n\n");
    printf("ENTER 0 TO EXIT\n\n");
    
    
    for(testers=0; studentid > 0; testers++){
        error1=0;
        result=0;
        sa=0;
        sb=0;
        totalscores=0;
        
        scanf("%d",&studentid);
        if(studentid==0)        //checks student number for exit request
            break;
        scanf("%d %d %d %d %d %d %d %d",&s1,&s2,&s3,&s4,&s5,&s6,&s7,&s8);
        
        
        if(testers==0)          //prints header one time instead of each time
        {
            printf("id\tSection A\tSection B\tResult\t\tComments\n");
            printf("----\t-----------\t-----------\t---------\t-----------\n");
        }
        
        if(s1>20||s1<0)         //for a score outside range of 0-20 add 1 to error1 (later if error 1 != 0 then Output Score incorrect.)
        {
            s1=0;
            error1++;
        }
        
        if(s2>20 || s2<0)
        {
            s2=0;
            error1++;
        }
        
        if(s3>20||s3<0)
        {
            s3=0;
            error1++;
        }
        
        if(s4>20||s4<0)
        {
            s4=0;
            error1++;
        }
        
        if(s5>20||s5<0)
        {
            s5=0;
            error1++;
        }
        
        if(s6>20||s6<0)
        {
            s6=0;
            error1++;
        }
        
        if(s7>20||s7<0)
        {
            s7=0;
            error1++;
        }
        
        if(s8>20||s8<0)
        {
            s8=0;
            error1++;
        }
        
        
        
        sb=0;               //for a nonzero score count one score reported from section B
        if(s5>0)
            sb++;
        if(s6>0)
            sb++;
        if(s7>0)
            sb++;
        if(s8>0)
            sb++;
        
        sa=0;               //for a non zero score count one score reported from secton A.
        if(s1>0)
            sa++;
        if(s2>0)
            sa++;
        if(s2>0)
            sa++;
        if(s3>0)
            sa++;
        if(s4>0)
            sa++;
        
        
        sa = sa - 1;            //for some reason when there is more than one score reported in Section A my programs reads an extra (i.e. for 2 scores program thinks 3 scores)
        totalscores = sa + sb;
        
        result=s1+s2+s3+s4+s5+s6+s7+s8;
            
            if(s1>0)           //if more questions than required are answered, then the first ones are counted and the later ones are disregarded.
            {
                if(s2>0)
                {
                    if(s3>0)
                        result = result- s4;
                }
            }

        if(s5>0)
        {
            if(s6>0)
            {
                if(s7>0)
                    result = result- s8;
            }
        }
        
        if(s1>0)
        {
            if(s2>0)
            {
                if(s3>0)
                {
                    if(s5>0)
                    {
                        if(s6>0)
                            result = result - s7;
                    }
                }
            }
        }
        printf("%d\t%d %d %d %d\t%d %d %d %d\t%d\t\t", studentid,s1,s2,s3,s4,s5,s6,s7,s8,result);
        
        if(error1>0)
        printf("Score incorrect. ");
        
        if(totalscores > 5)
        printf("More than 5. ");
        
        if(totalscores < 5)
        printf("Less than 5. ");
        
        if(sa > 3)
        printf("Too many from A. ");
        
        if(sb>3)
        printf("Too many from B. ");
        
        printf("\n");
        sum += result;
    }
    printf("\nTotal Students: %d\n", testers);
    printf("Average result: %.1f\n\n",average = sum/testers);
    
    return 0;
}
