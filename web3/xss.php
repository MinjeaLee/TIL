<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <script>
        alert("hi");
    </script>
    &lt;script&gt;
        alert("hi");
    &lt;/script&gt;
    <?php
        echo htmlspecialchars("<script> alert('hi'); </script>");
    ?>

</body>
</html>