BEGIN{ c=0;}
{
 if($1=="r")
 { c++;
printf("%s\t%s\n",$5,$11);
 }
}
END{ printf("The number of packets dropped =%d\n",c); }
