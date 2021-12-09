<template>
  <div class="home">
    <div class="container">

      <div
        class="flip-card"
        v-for="student in presentStudents"
        :key="student"
      >
        <div class="flip-card-inner">
          <div class="flip-card-front">
            <p class="header">{{student.firstName}}</p>
            <p class="subheader2">Checkade in</p>
            <p class="bodyText">{{currentTime()}}</p>
          </div>
          <div class="flip-card-back">
            <p class="subheader1">{{student.firstName}} {{student.lastName}}</p>
            <p class="subheader2">{{student.class}}</p>
            <p class="bodyText">Tidig 5 min</p>
          </div>
        </div>
      </div>

      <div
        class="flip-card"
        v-for="student in absentStudents"
        :key="student"
      >
        <div class="flip-card-inner">
          <div
            class="flip-card-front"
            style="background-color: grey"
          >
            <p class="header">{{student.firstName}}</p>
            <p class="subheader">{{currentTime()}}</p>
          </div>
          <div
            class="flip-card-back"
            style="background-color: grey"
          >
            <p class="subheader1">{{student.firstName}} {{student.lastName}}</p>
            <p class="subheader2">{{student.class}}</p>
            <p class="bodyText">Ej närvarande</p>
          </div>
        </div>
        <!-- class="studentCard"
        v-for="elev in documents"
        :key="elev"
        >
        <p class="name">{{elev["name"]}}</p>
        <p>{{getTime(elev["timestamp"])}}</p> -->
      </div>

    </div>
  </div>
</template>

<script>
// @ is an alias to /src
// import HelloWorld from '@/components/HelloWorld.vue'
import { db } from '../db'
export default {
  name: 'Home',
  components: {
    // HelloWorld
  },
  data () {
    return {
      presentStudents: [
        { firstName: 'Jonathan', lastName: 'Damsgaard Falck', class: "190S" },
        { firstName: 'Linus', lastName: 'Olofsson', class: "190S" },
        { firstName: 'Lucas', lastName: 'Venlock', class: "190S" }
      ],
      absentStudents: [
        { firstName: 'Jonathan', lastName: 'Damsgaard Falck', class: "190S" },
        { firstName: 'Jonathan', lastName: 'Damsgaard Falck', class: "190S" },
        { firstName: 'Jonathan', lastName: 'Damsgaard Falck', class: "190S" }
      ],
    }
  },
  created: function () {

  },
  firebase: {
    documents: db.ref('students/190S'),
  },
  methods: {
    currentTime () {
      const current = new Date()
      const time = current.getHours() + ":" + current.getMinutes()
      const Time = time
      return Time
    },
    getTime (timestamp) {
      const Time = new Date(timestamp)
      const time = Time.getHours() + ":" + Time.getMinutes()
      return time
    },
  }
}
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
