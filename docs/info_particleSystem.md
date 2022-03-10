# Particle System

## Emitters

Spawn particles every update

emission types: point, line, circle, square

```json
{
    "emitter" : {
        "rate" : 0,

        //Point
        "origin" : {"x": 0, "y": 0},

        //Line
        "pointA" : {"x": 0, "y": 0},
        "pointB" : {"x": 0, "y": 0},

        //Circle
        "origin" : {"x": 0, "y": 0},
        "radius" : 0,

        //Rectangle
        "origin" : {"x": 0, "y": 0},
        "size": {"w": 0, "h": 0},

        "life" : 0,
        "lifeRange" : {"min": 1, "max": 2}

    }
}
```

## Particles

show beheaviour every update untill they die

> 💡 **tip:** particles can be pooled beforehand when you know the maximum life time of the particle and the emission rate of the emitter

```json
{
    "particle" : {

        //General attributes
        "life" : 0,
        "position" : {"x": 0, "y": 0},
        "rotation" : 0,

        //Rendering attributes
        "texture" : 0,
        "color" : {"r": 0, "g": 0, "b": 0, "a": 0},

        //Modification attributes
        "velocity" : {"x": 0, "y": 0},
        "angularVelocity" : 0,
    }
}
```

## Reactors

Objects or systems that react with particles

attraction, repulsion