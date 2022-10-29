from datetime import date, datetime, timedelta
import csv
import itertools

def initialize_results_csv():
    fname = './nypd_arrests_results.csv'
    with open(fname, 'w') as f:testData
        header = "date,manhattan,kings,queens,bronx,staten_island\n"
        f.write(header)

        start_date = date(2006, 1, 1) 
        end_date = date(2021, 12, 31)    # perhaps date.now()

        delta = end_date - start_date   # returns timedelta

        for i in range(delta.days + 1):
            day = start_date + timedelta(days=i)
            f.write(str(day) + ",,,,,\n")

        f.close()

def process_data():
    fname = '../NYPD_Arrests_Data__Historic_.csv'
    with open(fname, 'r') as f:
        ct = 0
        for line in f:
            print(line.strip(),"YUH")
            ct+=1
            if ct > 10:
                break
        # with open('./nypd_arrests_results.csv', 'w') as g:

        #     # for item in csv:
        #     csvfile = csv.reader(f)

        #     start = datetime.now()

        #     ct = 0
        #     # itertools slices off just the 1st 1000
        #     for line in itertools.islice(csvfile,1000):
        #         ct += 1
        #         # Remove fluff
        #         out_string = str(line).replace('[','').replace(']','').replace('\'','').replace(', ',',')+"\n"
        #         g.write(out_string)
        #         print("Read", ct, "rows")

        #     end = datetime.now()

        #     runtime = end - start
        #     print("RUNTIME:", runtime)



    #     where date in item matches date in results.csv
    #     add count to date
    #     practice by doing this for just one date with a limited dataset
    #     TAKE IT SLOW, KEEP IT SIMPLE


def main():
    # initialize_results_csv()
    process_data()

if __name__=="__main__":
    main()

