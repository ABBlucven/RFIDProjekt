<template>
  <div class="home">
    <div class="container">
      <div class="flip-card" v-for="student in documents" :key="student">
        <div
          class="flip-card-inner"
          v-if="onTime(student['timestamp']) === 'onTime'"
        >
          <div class="flip-card-front">
            <p class="header">{{ student["name"].split(" ")[0] }} {{student["name"].split(" ")[1].split("")[0]}}</p>
            <p class="subheader2">Närvarande</p>
            <p class="bodyText">{{ getTime(student["timestamp"]) }}</p>
          </div>

          <div class="flip-card-back">
            <p class="subheader1">{{ student["name"] }}</p>
            <p class="subheader2">{{ student.class }}</p>
            <p class="subheader2">{{ getDeltaTime(student["timestamp"]) }} tidig</p>
          </div>
        </div>

        <div
          class="flip-card-inner"
          v-else-if="onTime(student['timestamp']) === 'late'"
        >
          <div class="flip-card-front" style="background-color: grey">
            <p class="header">{{ student["name"].split(" ")[0] }} {{student["name"].split(" ")[1].split("")[0]}}</p>
            <p class="subheader2">Försenad</p>
            <p class="subheader"></p>
          </div>
          <div class="flip-card-back" style="background-color: grey">
            <p class="subheader1">{{ student["name"] }}</p>
            <p class="subheader2">{{ student.class }}</p>
            <p class="subheader2">{{ getDeltaTime(student["timestamp"]) }} försenad</p>
          </div>
        </div>

        <div
          class="flip-card-inner"
          v-else-if="onTime(student['timestamp']) === 'notPresent'"
        >
          <div class="flip-card-front" style="background-color: grey">
            <p class="header">{{ student["name"].split(" ")[0] }} {{student["name"].split(" ")[1].split("")[0]}}</p>
            <p class="subheader2">Ej närvarande</p>
            <p class="subheader"></p>
          </div>
          <div class="flip-card-back" style="background-color: grey">
            <p class="subheader1">{{ student["name"] }}</p>
            <p class="subheader2">{{ student.class }}</p>
            <p class="subheader2">Ej närvarande</p>
          </div>
        </div>
      </div>
    </div>

   
  </div>
</template>

<script>
// @ is an alias to /src
// import HelloWorld from '@/components/HelloWorld.vue'
import { db } from "../db";
export default {
  name: "Home",
  components: {
    // HelloWorld
  },
  data() {
    return {
      currentIndex: 0,
      documents: [],
      calendar: [],
    };
  },
  firebase: {
    documents: db.ref("students/classes/190S"),
  },
  created() {
    function httpGetAsync(theUrl, callback) {
      var xmlHttp = new XMLHttpRequest();
      xmlHttp.onreadystatechange = function () {
        if (xmlHttp.readyState == 4 && xmlHttp.status == 200)
          callback(xmlHttp.responseText);
      };
      xmlHttp.open("GET", theUrl, true); // true for asynchronous
      xmlHttp.send(null);
    }

    httpGetAsync(
      "https://cloud.timeedit.net/abbindustrigymnasium/web/public1/ri657Q6QZZ9Z53Q5Y36nQ657y.ics",
      (data) => {
        var calendar = [];
        data = data.split(/\r?\n/);
        var lessonIndex = 0;
        data.forEach((element) => {
          var key = element.split(":")[0];
          var val = element.split(":")[1];
          if (key == "DTSTART") {
            var d = val.split("T")[0];
            var t = val.split("T")[1].split("00Z")[0];
            var date = new Date(
              d.slice(0, 4),
              parseInt(d.slice(4, 6)) - 1,
              d.slice(6, 8),
              parseInt(t.slice(0, 2)) + 1,
              t.slice(2, 4)
            );
            calendar[lessonIndex]["start"] = date;
          }
          if (key == "DTEND") {
            d = val.split("T")[0];
            t = val.split("T")[1].split("00Z")[0];
            date = new Date(
              d.slice(0, 4),
              parseInt(d.slice(4, 6)) - 1,
              d.slice(6, 8),
              parseInt(t.slice(0, 2)) + 1,
              t.slice(2, 4)
            );

            calendar[lessonIndex]["end"] = date;
          }
          if (key == "UID") {
            calendar[lessonIndex]["UID"] = val;
          }
          if (key == "BEGIN" && val != "VCALENDAR") {
            lessonIndex++;
            calendar[lessonIndex] = {};
          }
        });
        calendar.sort(function (a, b) {
          return a.start - b.start;
        });
        calendar.forEach((element) => {
          if (Date.parse(element.end) < new Date()) {
            this.currentIndex++;
          }
        });
        console.log(calendar);
        this.calendar = calendar;
      }
    );
  },

  methods: {
    currentTime() {
      const current = new Date();
      const time = current.getHours() + ":" + current.getMinutes();
      const Time = time;
      return Time;
    },
    getTime(timestamp) {
      const Time = new Date(timestamp);
      var time = Time.getHours() + ":" + Time.getMinutes();
      return time;
    },
    getDeltaTime(timestamp) {
      let diffInMilliSeconds =
        Math.abs(
          Date.parse(this.calendar[this.currentIndex]["start"]) -
            new Date(timestamp)
        ) / 1000;
      var time = "";
      const hours = Math.floor(diffInMilliSeconds / 3600) % 24;
      diffInMilliSeconds -= hours * 3600;
      const minutes = Math.floor(diffInMilliSeconds / 60) % 60;
      diffInMilliSeconds -= minutes * 60;
      if (hours > 0) {
        time = hours + " h " + minutes + " min";
      } else {
        time = minutes + " min";
      }
      return time;
    },
    onTime(timestamp) {
      var val = ''
      if (timestamp > Date.parse(this.calendar[this.currentIndex - 1]["end"])) {
        console.log("_._")
      }
      if (
        timestamp < Date.parse(this.calendar[this.currentIndex]["start"]) &&
        timestamp > Date.parse(this.calendar[this.currentIndex - 1]["end"])
      ) {
        val = "onTime";
      }
      else if (
        timestamp > Date.parse(this.calendar[this.currentIndex]["start"]) &&
        timestamp < Date.parse(this.calendar[this.currentIndex]["end"])
      ) {
        val = "late";
      }
      else if (
        timestamp < Date.parse(this.calendar[this.currentIndex]["start"])
      ) {
        val =  "notPresent";
      }
    
      return val
    },
  },
};
</script>

<style scoped>
.home {
  text-align: center;
  font-family: Arial, sans-serif;
}

.container {
  display: flex;
  flex-wrap: wrap;
  justify-content: center;
  padding: 30px;
}

.header {
  font-size: 30px;
  font-weight: bold;
}

.subheader1 {
  font-size: 20px;
  font-weight: bold;
}

.subheader2 {
  font-size: 15px;
  font-weight: normal;
  margin: 1px 0px;
}

.bodyText {
  font-size: 10px;
  font-weight: lighter;
  margin: 1px 0px;
}

.flip-card {
  background-color: transparent;
  min-width: 200px;
  height: 150px;
  margin: 20px;
  /*box-shadow: 8px 8px 20px grey;*/
  perspective: 1000px;
}

.flip-card-inner {
  position: relative;
  width: 100%;
  height: 100%;
  text-align: center;
  transition: transform 0.8s;
  transform-style: preserve-3d;
  box-shadow: 8px 8px 20px grey;
}

.flip-card:hover .flip-card-inner {
  transform: rotateY(180deg);
  box-shadow: none;
}

.flip-card-front,
.flip-card-back {
  position: absolute;
  width: 100%;
  height: 100%;
  -webkit-backface-visibility: hidden; /* Safari */
  backface-visibility: hidden;
}

.flip-card-front {
  background-color: rgb(174, 225, 255);
  color: black;
}

.flip-card-back {
  background-color: rgb(138, 211, 253);
  color: rgb(0, 0, 0);
  transform: rotateY(180deg);
  font-size: 20px;
}
</style>
