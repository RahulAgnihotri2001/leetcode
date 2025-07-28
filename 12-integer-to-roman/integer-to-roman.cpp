class Solution {
public:
    string intToRoman(int nums) {
        int x=nums;
        string answer="";
        while(nums>=1000){
            answer+= "M";
            nums-=1000;
        }
        if(nums>=900){
            answer+="CM";
            nums-=900;
        }
        while(nums>=500){
            answer+= "D";
            nums-=500;
        }
        if(nums>=400){
            answer+="CD";
            nums-=400;
        }
        while(nums>=100){
            answer+="C";
            nums-=100;
        }
        if(nums>=90){
            answer+="XC";
            nums-=90;
        }
        while(nums>=50){
            answer+="L";
            nums-=50;
        }
        if(nums>=40){
            answer+="XL";
            nums-=40;
        }
        while(nums>=10){
            answer+="X";
            nums-=10;
        }
        if(nums>=9){
            answer+="IX";
            nums-=9;
        }
        while(nums>=5){
            answer+="V";
            nums-=5;
        }
        if(nums>=4){
            answer+="IV";
            nums-=4;
        }
        while(nums>=1){
            answer+="I";
            nums-=1;
        }
        return answer;
    }
};