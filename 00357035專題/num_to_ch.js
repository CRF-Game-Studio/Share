function f(s){
    var INT_NUM = parseInt(s);
    var return_str = "";
    if(INT_NUM / 10 == 0){
        s = "0" + s;
    }  
    if(INT_NUM % 10 == 0){
        console.log("if  "+s[0]);
        return_str = trans_ch(s[0]);
    }
    else {
        return_str = trans_ch(s[0]) + trans_ch(s[1]);
        
    }
    return return_str;
}

function trans_ch(str){
    
    switch(parseInt(str)){ 
        case 1:return "一";
        case 2:return "二";
        case 3:return "三";
        case 4:return "四";
        case 5:return "五";
        case 6:return "六";
        case 7:return "七";
        case 8:return "八";
        case 9:return "九";
    }
}
