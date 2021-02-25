$(loadList);

function loadList(){
    $('#list').html("<b>Wird geladen...</b>");

    $.ajax({
        'url' : 'http://fklein.bplaced.net/rest_oo/php/CarRestController.php',
        'type' : 'POST',
        'data' : {
            'action' : 'getAll'
        },
        'success' : function(data) {
            data = JSON.parse(data);

            var html = "";
            $.each(data, function(key, val){
                html += "<div class='car'><table width='100%'><tr>" +
                "<td><b>Marke:</b></td>" + "<td>" + val.brand + "</td>" +
                "<td><b>Model:</b></td>" + "<td>" + val.model + "</td>" +
                "<td><b>Farbe:</b></td>" + "<td><div class='color' style='background-color:" + val.color + "'></div></td>" +
                "<td><b>Baujahr:</b></td>" + "<td>" + val.year + "</td>" +
                "</tr></table></div><br>";
            });
            $('#list').html(html);
        },
        'error' : function(request,error) {
            $('#list').html("<b>Fehler beim Laden</b>");
        }
    });
}

function addFromForm(){

}