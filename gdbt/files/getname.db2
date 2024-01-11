CREATE PROCEDURE getname( IN innumber INT, OUT outname VARCHAR(200) )
LANGUAGE SQL
BEGIN    
	SELECT name INTO outname FROM person WHERE id = innumber;
END@