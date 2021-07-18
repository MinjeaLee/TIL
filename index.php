<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1>WEB</h1>
    <nav>
        <ol>
            <li><a href="index.php?id=html">HTML</a></li>
            <li><a href="index.php?id=css">CSS</a></li>
            <li><a href="index.php?id=java">JAVA</a></li>
        </ol>
    </nav>

    <h2>
        <?php 
            echo $_GET['id'];
        ?>
    </h2>
    <p>
        Lorem ipsum dolor sit, amet consectetur adipisicing elit. Corrupti, ducimus sed aut sit alias molestias voluptatem provident fuga cupiditate consequatur? Itaque beatae ex corrupti voluptatibus et, quae iusto voluptatum odio.
    </p>
</body>
</html>