var decimal_ip = [];
var binary_ip = [];
$("#ip_type").change(refreshInfos());
$(".decimal_input").change(refreshInfos());

function refreshInfos(){
    if($("#ip_type").val() == "decimal"){
        refreshDecimalCalculations();
    }
    else if($("#ip_type").val() == "binary"){
        refreshBinaryCalculations();
    }

    $("#decimal_ip").html(decimal_ip[0] + "." + decimal_ip[1] + "." + decimal_ip[2] + "." + 
                            decimal_ip[3]);

    $("#binary_ip").html(
        binary_ip[0][0] + binary_ip[0][1] + binary_ip[0][2] + binary_ip[0][3] +
        binary_ip[0][4] + binary_ip[0][5] + binary_ip[0][6] + binary_ip[0][7] + "." +
        binary_ip[1][0] + binary_ip[1][1] + binary_ip[1][2] + binary_ip[1][3] +
        binary_ip[1][4] + binary_ip[1][5] + binary_ip[1][6] + binary_ip[1][7] + "." +
        binary_ip[2][0] + binary_ip[2][1] + binary_ip[2][2] + binary_ip[2][3] +
        binary_ip[2][4] + binary_ip[2][5] + binary_ip[2][6] + binary_ip[2][7] + "." +
        binary_ip[3][0] + binary_ip[3][1] + binary_ip[3][2] + binary_ip[3][3] +
        binary_ip[3][4] + binary_ip[3][5] + binary_ip[3][6] + binary_ip[3][7]
    );
}

function refreshDecimalCalculations(){
    decimal_ip[0] = $("#decimal_input_1").val();
    decimal_ip[1] = $("#decimal_input_2").val();
    decimal_ip[2] = $("#decimal_input_3").val();
    decimal_ip[3] = $("#decimal_input_4").val();

    binary_ip[0] = decimalToBinary(decimal_ip[0]);
    binary_ip[1] = decimalToBinary(decimal_ip[1]);
    binary_ip[2] = decimalToBinary(decimal_ip[2]);
    binary_ip[3] = decimalToBinary(decimal_ip[3]);
}

function decimalToBinary(decimal){
    var binary = [];
    if(decimal >= 128){
        binary[0] = 1;
    }
    else{
        binary[0] = 0;
    }
    decimal -= 128;

    if(decimal >= 64){
        binary[1] = 1;
    }
    else{
        binary[1] = 0;
    }
    decimal -= 64;

    if(decimal >= 32){
        binary[2] = 1;
    }
    else{
        binary[2] = 0;
    }
    decimal -= 32;
    
    if(decimal >= 16){
        binary[3] = 1;
    }
    else{
        binary[3] = 0;
    }
    decimal -= 16;

    if(decimal >= 8){
        binary[4] = 1;
    }
    else{
        binary[4] = 0;
    }
    decimal -= 8;

    if(decimal >= 4){
        binary[5] = 1;
    }
    else{
        binary[5] = 0;
    }
    decimal -= 4;

    if(decimal >= 2){
        binary[6] = 1;
    }
    else{
        binary[6] = 0;
    }
    decimal -= 2;

    if(decimal >= 1){
        binary[7] = 1;
    }
    else{
        binary[7] = 0;
    }
    decimal -= 1;

    return binary;
}