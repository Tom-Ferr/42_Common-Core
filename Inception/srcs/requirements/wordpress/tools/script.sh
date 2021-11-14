

awk ' {
    if ($2 == "\047DB_NAME\047,")
    {
        print "define( \047DB_NAME\047, \047"ENVIRON["MYSQL_DATABASE"]"\047 );"
    }
    else if ($2 == "\047DB_USER\047,")
    {
        print "define( \047DB_USER\047, \047"ENVIRON["MYSQL_USER"]"\047 );"
    }
    else if ($2 == "\047DB_PASSWORD\047,")
    {
        print "define( \047DB_PASSWORD\047, \047"ENVIRON["MYSQL_PASSWORD"]"\047 );"
        
    }
    else
    {
        print $0
    }
  }' /wp-config.php