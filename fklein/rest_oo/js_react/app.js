// import React from 'react';
// import ReactDOM from 'react-dom';
// import Button from '@material-ui/core/Button';
const {
    Button,
    TextField,
    createMuiTheme,
    ThemeProvider
} = MaterialUI;

const darkTheme = createMuiTheme({
    palette: {
      type: "dark",
    }
});

function App() {
    return (
        <ThemeProvider theme={darkTheme}>
            <TextField id="brand" label="Marke"/> <TextField id="model" label="Modell"/><br/>
            <br/>
            <TextField id="color" type="color" style={{width: '195px'}} label="Farbe"/> <TextField id="year"  type="number" label="Baujahr"/><br/>
            <br/>
            <Button variant="contained" color="primary" id="add" onClick={() => { addFromForm() }}>Hinzufügen</Button>
        </ThemeProvider>
  );
}

ReactDOM.render(<App />, document.querySelector('#app'));

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