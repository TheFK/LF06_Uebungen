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
                html += "<div>" + val.brand + "</div><br>"
            });
            $('#list').html(html);
        },
        'error' : function(request,error)
        {
            $('#list').html("<b>Fehler beim Laden</b>");
        }
    });
}

function addFromForm(){

}