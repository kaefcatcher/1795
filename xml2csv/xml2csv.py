import xml.etree.ElementTree as ET
import csv
import sys, getopt


try:
    opts, args = getopt.getopt(sys.argv[1:],"hp:",["help","path="])
except getopt.GetoptError as err:
    print (str(err))
    sys.exit(2)
for opt, arg in opts:
    if opt in ('-h', '--help'):
        print ('xml2csv.py')
        print ('-h, --help                      Help!')
        print ('-p, --path                      Path to trace.xml file')
        sys.exit()
    elif (opt == '-p') or  (opt == '--path'):
        path = arg
    else:
        assert False, "unhandled option"


tree = ET.parse(path)
root = tree.getroot()

csvfile = open("trace.csv",'w')
csvfile_writer = csv.writer(csvfile)

for timestep in root:
    for vehicle in timestep:
        csv_line = [vehicle.attrib["x"], vehicle.attrib["y"], 0]
        csvfile_writer.writerow(csv_line)
csvfile.close()



