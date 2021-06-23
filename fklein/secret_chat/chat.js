var last_time = -1;
$(start);

function start(){
    getNewMessages();
    setInterval(function(){ 
        getNewMessages(); 
    }, 5000);
}

function getNewMessages(){
    console.log(last_time);
    $.ajax({
        'url' : 'http://fklein.bplaced.net/secret_chat/chat.php',
        'type' : 'POST',
        'data' : {
            'action' : 'read',
            'last_time' : last_time
        },
        'success' : function(data) {
            data = JSON.parse(data);

            var html = $('#chat').html();
            $.each(data, function(key, val){
                html += val.sender + ": " + val.text + "<br>";
            });

            $('#chat').html(html);
            last_time = data[data.length - 1]["time"];
        },
        'error' : function(request,error) {
            $('#chat').html("<b>Fehler</b>");
        }
    });
}

function sendMessage(){
    var sender = $('#chat_sender').val();
    var message = $('#chat_message').val();
    $.ajax({
        'url' : 'http://fklein.bplaced.net/secret_chat/chat.php',
        'type' : 'POST',
        'data' : {
            'action' : 'write',
            'sender' : sender,
            'message' : message
        },
        'success' : function(data) {
            $('#chat_message').val("");
        }
    });
}