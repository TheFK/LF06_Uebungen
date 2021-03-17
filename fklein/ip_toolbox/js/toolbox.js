var decimal_ip = [];
var binary_ip = [];
var hexadecimal_ip = [];
var ip_class = "";

$(".decimal_input").change(function(){
    refreshInfos();
});

function refreshInfos(){
    refreshDecimalCalculations();

    $("#ip_decimal").html(
        decimal_ip[0] + "." + 
        decimal_ip[1] + "." + 
        decimal_ip[2] + "." + 
        decimal_ip[3]
    );

    $("#ip_binary").html(
        binary_ip[0] + "." +
        binary_ip[1] + "." +
        binary_ip[2] + "." +
        binary_ip[3]
    );

    $("#ip_hexadecimal").html(
        hexadecimal_ip[0] + "." +
        hexadecimal_ip[1] + "." +
        hexadecimal_ip[2] + "." +
        hexadecimal_ip[3]
    );

    $("#ip_class").html(ip_class);
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

    hexadecimal_ip[0] = decimalToHexadecimal(decimal_ip[0]);
    hexadecimal_ip[1] = decimalToHexadecimal(decimal_ip[1]);
    hexadecimal_ip[2] = decimalToHexadecimal(decimal_ip[2]);
    hexadecimal_ip[3] = decimalToHexadecimal(decimal_ip[3]);

    ip_class = classOfCurrentIp();
}

function decimalToBinary(decimal){
    var binary = "";
    
    var i;
    for (i = 0; i < 8; i++) {
        var bit = decimal % 2;
        binary = "" + bit + binary;
        decimal = decimal / 2;
        if(bit == 1){
            decimal -= 0.5;
        }
    }
    return binary;
}

function decimalToHexadecimal(decimal){
    var hexadecimal = "";
    
    var i;
    for (i = 0; i < 2; i++) {
        var hex = numberToHex(decimal % 16);
        hexadecimal = "" + hex + hexadecimal;
        decimal = decimal / 2;
        decimal = Math.floor(decimal);
    }
    return hexadecimal;
}

function numberToHex(number){
    switch (number){
        case 10:
            return 'A';
        case 11:
            return 'B';
        case 12:
            return 'C';
        case 13:
            return 'D';
        case 14:
            return 'E';
        case 15:
            return 'F';
        default:
            return number;
    }
}

function classOfCurrentIp(){
    if(decimal_ip[0] > 0 && decimal_ip[0] <= 127){
        return 'A';
    }
    else if(decimal_ip[0] > 127 && decimal_ip[0] <= 191){
        return 'B';
    }
    else if(decimal_ip[0] > 191 && decimal_ip[0] <= 223){
        return 'C';
    }
    else if(decimal_ip[0] > 223 && decimal_ip[0] <= 239){
        return 'D';
    }
    else if(decimal_ip[0] > 239 && decimal_ip[0] <= 255){
        return 'E';
    }
    else{
        return 'Unbekannte Klasse';
    }
}