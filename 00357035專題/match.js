function matching(msg, root){
    var obj = {};
    obj.value = false;
    var return_msg = [];
    var tag = [];//tag [i][j] : i: 第幾部分 j:頭 尾 type 
    var num_str;
    var part = 0;
    for(var i in root){
        var pre = 0;
        for(var j in root[i]){
            
            for(var k = 1; k < root[i][j]; k++){    
                var temp_index = msg.indexof(root[i][j][k]);
                if(temp_index != -1){
                    if(temp_index != pre){
                        tag[part] = [];
                        tag[part][0] = pre;
                        tag[part][1] = temp_index;
                        tag[part][2] = '@';
                        pre = temp_index;
                        part ++;
                    }
                    tag[part] = [];
                    tag[part][0] = temp_index;
                    tag[part][1] = temp_index + root[i][j][k].length;
                    tag[part][2] = root[i][j][0];
                    pre = tag[part][1];
                    part++;
                }
            }
        }
        if (pre == msg.length){
            obj.value = true;
            break;    
        } 
    }
    for(var i = 0; i < part; i++){
        return_msg[i] = [];
        return_msg[i][0] = tag[i][2];
        return_msg[i][1] = msg.substring(tag[i][0],tag[i][1]);
    }
    obj.return_msg = return_msg;
    
    return return_msg;
}