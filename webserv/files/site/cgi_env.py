import os

print("The PATH_INFO is: " + os.environ.get("PATH_INFO"))
print("The QUERY_STRING is: " + os.environ.get("QUERY_STRING"))