<?php
    require_once("lib/print.php");
    require_once("view/top.php");
?>
    <h1>
        <?php echo $_GET['id']." modify"; ?>
    </h1>

    <form action="modify_process.php" method="post">
        <input type="hidden" name="old_title" value="<?php echo $_GET['id']?>" >
        <p><input type="text" name="title" value="<?php print_title(); ?>"></p>
        <p><textarea name="content"  cols="30" rows="10"><?php Print_content(); ?></textarea></p>
        <p><input type="submit" value="submit"></p>
    </form>
<?php
    require("view/bottom.php");
?>