$(loadList);

function loadList(){
    $('#list').html("<b>Wird geladen...</b>");
    $('#list').css("height", "50px");

    $.ajax({
        'url' : 'http://fklein.bplaced.net/rest_oo/php/CarRestController.php',
        'type' : 'POST',
        'data' : {
            'action' : 'getAll'
        },
        'success' : function(data) {
            data = JSON.parse(data);

            var html = "<table class='cars'>";
            $.each(data, function(key, val){
                html += "<tr>" +
                "<td><b>Marke:</b></td>" + "<td>" + val.brand + "</td>" +
                "<td><b>Model:</b></td>" + "<td>" + val.model + "</td>" +
                "<td><b>Farbe:</b></td>" + "<td><div class='color' style='background-color:" + val.color + "'></div></td>" +
                "<td><b>Baujahr:</b></td>" + "<td>" + val.year + "</td>" +
                "</tr>";
            });
            html += "</table>";

            $('#list').html(html);
            $('#list').css("height", "auto");
        },
        'error' : function(request,error) {
            $('#list').html("<b>Fehler beim Laden</b>");
        }
    });
}

function addFromForm(){
    var form_data = '{ ' +
        '"brand":"' + $("#brand").val() + '", ' +
        '"model":"' + $("#model").val() + '", ' +
        '"color":"' + $("#color").val() + '", ' +
        '"year":"' + $("#year").val() + '"' +
    ' }';

    // var car = JSON.parse(form_data);

    $.ajax({
        'url' : 'http://fklein.bplaced.net/rest_oo/php/CarRestController.php',
        'type' : 'POST',
        'data' : {
            'action' : 'add',
            'data' : form_data
        },
        'success' : function(data) {
            loadList();
        }
    });
}