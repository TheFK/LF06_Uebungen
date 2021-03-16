var decimal_ip;
var binary_ip;
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
}

function refreshDecimalCalculations(){
    decimal_ip[0] = $("#decimal_input_1");
    decimal_ip[1] = $("#decimal_input_2");
    decimal_ip[2] = $("#decimal_input_3");
    decimal_ip[3] = $("#decimal_input_4");

    binary_ip[0] = decimalToBinary(decimal_ip[0]);
    binary_ip[1] = decimalToBinary(decimal_ip[1]);
    binary_ip[2] = decimalToBinary(decimal_ip[2]);
    binary_ip[3] = decimalToBinary(decimal_ip[3]);
}