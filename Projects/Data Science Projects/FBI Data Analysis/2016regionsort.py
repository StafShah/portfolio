# Initial Setup
import json
import pandas as pd

with open("FBI_CrimeData_2016.json", 'r') as file:
    crime_data = json.load(file)

file.close()

violentList = ['Murder', 'Rape', 'Assault', 'Robbery']
nonviolentList = ['Burglary', 'Theft', 'Vehicle_Theft']

# Functions
def initializeCrimeDict(data, stat, sortBy):
    resultDict = {}
    
    if isinstance(stat, list):
        for i in data:
            if i[sortBy] in resultDict:
                for c in stat:
                    resultDict[i[sortBy]] += int(i[c])
            else:
                resultDict[i[sortBy]] = int(i[stat[0]])
                for n in range(1, len(stat)):
                    resultDict[i[sortBy]] += int(i[stat[n]])
    else:
        for i in data:
            if i[sortBy] in resultDict:
                resultDict[i[sortBy]] += int(i[stat])
            else:
                resultDict[i[sortBy]] = int(i[stat])
    
    return resultDict

def crimeChart(data, crime):
    pdDict = {'Region': pd.Series(list(data.keys())), 'Incidents': pd.Series(list(data.values()))}
    d = pd.DataFrame(pdDict)
    print(crime + " by Region\n", d, "\n")
    d.plot.bar(legend=False, figsize=(6,6), x='Region', y='Incidents', color=['blue', 'orange', 'green', 'red'])
    return

def crimeTable(data, crime):
    average = sum(data.values()) / len(data)
    
    print('\nNational Average ' + crime + ': ' + str(int(average)) + '\n')
    print(f"{'State': <25}{'Crimes': <10}{'Distance from Mean'}")
    
    for s in data:
        print(f"{s: <25}{data[s]:<10}{int(data[s] - average): <1}")
    
# Dataframes and Bar Charts by Region
murder_by_region = initializeCrimeDict(crime_data, 'Murder', 'Region')
violent_by_region = initializeCrimeDict(crime_data, violentList, 'Region')
nonviolent_by_region = initializeCrimeDict(crime_data, nonviolentList, 'Region')

crimeChart(murder_by_region, 'Murder')
crimeChart(violent_by_region, 'Violent Crimes')
crimeChart(nonviolent_by_region, 'Nonviolent Crimes')

# String Tables by State
murder_by_state = initializeCrimeDict(crime_data, 'Murder', 'State')
violent_by_state = initializeCrimeDict(crime_data, violentList, 'State')
nonviolent_by_state = initializeCrimeDict(crime_data, nonviolentList, 'State')

crimeTable(murder_by_state, 'Murders')
crimeTable(violent_by_state, 'Violent Crimes')
crimeTable(nonviolent_by_state, 'Nonviolent Crimes')
