<!DOCTYPE html>
<html>
<head>
    <title>Submit Data</title>
</head>
<body>
<h1>Submit Data</h1>
<form action="/submit" method="post">
    <label for="userData">User Data:</label>
    <input type="text" id="userData" name="userData" placeholder="id=1:name=zhansan:age=18"><br><br>

    <label for="timestampData">Timestamp Data:</label>
    <input type="text" id="timestampData" name="timestampData" placeholder="2023-10-01 12:34:56.789"><br><br>

    <button type="submit">Submit</button>
</form>
<c:if test="${not empty error}">
    <p style="color:red;">${error}</p>
</c:if>
</body>
</html>