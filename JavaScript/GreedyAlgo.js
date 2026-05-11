class BoothScheduler {
    constructor(totalBooths) {
        this.booths = [];

        for (let i = 0; i < totalBooths; i++) {
            this.booths.push({
                id: i + 1,
                freeAt: 0
            });
        }
    }

    assignPerson(arrivalTime, serviceTime) {

        let bestBooth = this.booths[0];

        for (let booth of this.booths) {
            if (booth.freeAt < bestBooth.freeAt) {
                bestBooth = booth;
            }
        }

        let startTime = Math.max(arrivalTime, bestBooth.freeAt);
       
        let endTime = startTime + serviceTime;
       
        bestBooth.freeAt = endTime;

        console.log("Person Arrived:", arrivalTime);
        console.log("Service Time:", serviceTime);
        console.log("Assigned Booth:", bestBooth.id);
        console.log("Start Time:", startTime);
        console.log("Finish Time:", endTime);
        console.log("\n\n");
    }
}

const scheduler = new BoothScheduler(3);

scheduler.assignPerson(2, 6);

scheduler.assignPerson(2, 5);

scheduler.assignPerson(3, 6);

scheduler.assignPerson(5, 3);

// scheduler.assignPerson(8,2);
