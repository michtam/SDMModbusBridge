const char index_page[] PROGMEM = R"=====(
<html>
  <head>
    <style>
      table.customTable {
        width: 50%;
        background-color: #FFFFFF;
        border-collapse: collapse;
        border-width: 2px;
        border-color: #7EA8F8;
        border-style: solid;
        color: #000000;
      }

      table.customTable td, table.customTable th {
        border-width: 2px;
        border-color: #7EA8F8;
        border-style: solid;
        padding: 5px;
       }

      table.customTable thead {
        background-color: #7EA8F8;
      }
    </style>
  </head>
  <body>
    <h1>Modbus Bridge for SDM630</h1>
    <h2>States</h2>
    <table class="customTable">
      <thead>
        <tr>
          <th>Register address</th>
          <th>Register Name</th>
          <th>Raw HEX</th>
          <th>Value</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <td>Row 1, Cell 1</td>
          <td>Row 1, Cell 2</td>
          <td>Row 1, Cell 3</td>
          <td>Row 1, Cell 4</td>
        </tr>
        <tr>
          <td>Row 2, Cell 1</td>
          <td>Row 2, Cell 2</td>
          <td>Row 2, Cell 3</td>
          <td>Row 2, Cell 4</td>
        </tr>
      </tbody>
    </table>

    <h2>OTA Update</h2>
    <form method="POST" action="/update" enctype="multipart/form-data">
      <input type="file" name="update">
      <input type="submit" value="Update">
    </form>
  </body>
</html>
)=====";

const char page_404[] PROGMEM = R"=====(
404 Not Found
)=====";
