var last_time = -1;
$(start);

function start(){
    getNewMessages();

    $('#chat_sender').val(getCookie("name"));
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

            var html = "";
            $.each(data, function(key, val){
                val.text = val.text.replace(/\n/g, "<br />")
                val.text = replaceEmojis(val.text);
                html += "<tr><td>" + 
                            "<b style='color:" + getRandomColor() + "'>" + val.sender + ":</b>" +
                        "</td>" +
                        "<td>" + val.text + "</td>" +
                        "<td><i style='color: gray;'>" + val.time + "</i></td>" +
                        "</tr>";
            });
            $('#chat').append(html);
            
            $("#connection_issues").css("left", "-300px");

            setTimeout(function() {
                getNewMessages(); 
            }, 2500);

            if(data.length > 0){
                last_time = data[data.length - 1]["time"];
                $('#chat_box').animate({scrollTop: $('#chat_box').prop('scrollHeight')});
            }
        },
        'error' : function(request,error) {
            $("#connection_issues").css("left", "50vw");

            setTimeout(function() {
                getNewMessages(); 
            }, 2500);
        }
    });
}

function sendMessage(){
    var sender = $('#chat_sender').val();
    var message = $('#chat_message').val();
    sender = sender.trim();
    message = message.trim();
    if(sender.length > 0 && message.length > 0){
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
                setCookie("name", $('#chat_sender').val());
            }
        });
    }
    else{
        alert("Bitte gib einen Namen und eine Nachricht ein!");
    }
}

function getRandomColor() {
    var letters = '0123456789ABCDEF';
    var color = '#';
    for (var i = 0; i < 6; i++) {
      color += letters[Math.floor(Math.random() * 16)];
    }
    return color;
}

function setCookie(name,value,days) {
    var expires = "";
    if (days) {
        var date = new Date();
        date.setTime(date.getTime() + (days*24*60*60*1000));
        expires = "; expires=" + date.toUTCString();
    }
    document.cookie = name + "=" + (value || "")  + expires + "; path=/";
}
function getCookie(name) {
    var nameEQ = name + "=";
    var ca = document.cookie.split(';');
    for(var i=0;i < ca.length;i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1,c.length);
        if (c.indexOf(nameEQ) == 0) return c.substring(nameEQ.length,c.length);
    }
    return null;
}
function eraseCookie(name) {   
    document.cookie = name +'=; Path=/; Expires=Thu, 01 Jan 1970 00:00:01 GMT;';
}

function replaceEmojis(text){
    text = text.replaceAll(':D', String.fromCodePoint(0x1F600));
    text = text.replaceAll(':)', String.fromCodePoint(0x1F642));
    text = text.replaceAll(':(', String.fromCodePoint(0x1F641));
    text = text.replaceAll('<3', String.fromCodePoint(0x2764));
    text = text.replaceAll(':gun:', String.fromCodePoint(0x1F52B));
    text = text.replaceAll(':pride:', String.fromCodePoint(0x1F308));

    return text;
}